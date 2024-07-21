using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ArduinoControlAppGuiSide
{
    public partial class Form1 : Form
    {
        private static string[] existingSerialPorts = SerialPort.GetPortNames();

        public static SerialPort port = null;

        private static string LastParametersFileName = "lastPort.txt";

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

            this.Controls.AddRange(UIElements.GenerateUIElements(existingSerialPorts).ToArray());

            #endregion UI_ELEMENTS

            

            if (!File.Exists(LastParametersFileName))
                File.WriteAllText(LastParametersFileName, "COM1");

            var lastUsedPort = File.ReadAllLines("lastPort.txt");

            if (existingSerialPorts.Contains(lastUsedPort[0]))
                ((ComboBox)this.Controls[0]).Text = lastUsedPort[0];
            else
                ((ComboBox)this.Controls[0]).Text = "";


        }

        private void CommandButtonClick(object sender, EventArgs e)
        {
            var cmd = ((Button)sender).Tag.ToString();

            port.Write(cmd);
        }

        private void ConnectBtnClick(object sender, EventArgs e)
        {
            this.Controls[0].Visible = false;
            this.Controls[1].Visible = false;
            this.Controls[2].Visible = true;
            this.Controls[3].Visible = true;
            this.Controls[4].Visible = true;
            this.Controls[5].Visible = true;
            this.Controls[6].Visible = true;
            this.Controls[7].Visible = true;
            this.Controls[8].Visible = true;
            this.Controls[9].Visible = true;

            port = new SerialPort(((ComboBox)this.Controls[0]).SelectedItem.ToString(), 9600, Parity.None, 8);

            if (port.IsOpen)
                port.Close();

            port.Open();

            File.WriteAllText(LastParametersFileName, port.PortName);
        }
    }
}
