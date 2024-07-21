using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ArduinoControlAppGuiSide
{
    public partial class Form1 : Form
    {
        public static SerialPort port = null;

        public Form1()
        {
            #region UI_ELEMENTS

            UIElements.btnConnect.Click += new System.EventHandler(this.ConnectBtnClick);
            UIElements.btnOnD02.Click += new System.EventHandler(this.CommandButtonClick);
            UIElements.btnOffD02.Click+= new System.EventHandler(this.CommandButtonClick);
            UIElements.btnOnD03.Click += new System.EventHandler(this.CommandButtonClick);
            UIElements.btnOffD03.Click += new System.EventHandler(this.CommandButtonClick);
            UIElements.btnOnD04.Click += new System.EventHandler(this.CommandButtonClick);
            UIElements.btnOffD04.Click += new System.EventHandler(this.CommandButtonClick);
            UIElements.btnOnD05.Click += new System.EventHandler(this.CommandButtonClick);
            UIElements.btnOffD05.Click += new System.EventHandler(this.CommandButtonClick);
            
            InitializeComponent();

            this.Controls.AddRange(UIElements.Config().ToArray());

            #endregion UI_ELEMENTS
        }

        private void CommandButtonClick(object sender, EventArgs e)
        {
            var cmd = ((Button)sender).Tag.ToString();

            port.Write(cmd);
        }

        private void ConnectBtnClick(object sender, EventArgs e)
        {
            this.Controls[0].Visible = false;
            this.Controls[1].Visible = true;
            this.Controls[2].Visible = true;
            this.Controls[3].Visible = true;
            this.Controls[4].Visible = true;
            this.Controls[5].Visible = true;
            this.Controls[6].Visible = true;
            this.Controls[7].Visible = true;
            this.Controls[8].Visible = true;

            port = new SerialPort("COM11", 9600, Parity.None, 8);

            if (port.IsOpen)
                port.Close();

            port.Open();
        }
    }
}
