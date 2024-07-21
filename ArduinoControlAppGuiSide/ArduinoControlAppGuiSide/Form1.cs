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

        private static SerialPort port = null;

        private static string LastParametersFileName = "lastPort.txt";

        public Form1()
        {
            #region UI_ELEMENTS

            UIElements.btnConnect.Click += new System.EventHandler(this.ConnectBtnClick);
            UIElements.btnOnD02.Click += new System.EventHandler(this.CommandButtonClick);
            UIElements.btnOffD02.Click += new System.EventHandler(this.CommandButtonClick);
            UIElements.btnOnD03.Click += new System.EventHandler(this.CommandButtonClick);
            UIElements.btnOffD03.Click += new System.EventHandler(this.CommandButtonClick);
            UIElements.btnOnD04.Click += new System.EventHandler(this.CommandButtonClick);
            UIElements.btnOffD04.Click += new System.EventHandler(this.CommandButtonClick);
            UIElements.btnOnD05.Click += new System.EventHandler(this.CommandButtonClick);
            UIElements.btnOffD05.Click += new System.EventHandler(this.CommandButtonClick);

            this.Size = new Size(700, 500);

            InitializeComponent();

            this.Text = "Valdymas";

            this.Controls.AddRange(UIElements.GenerateUIElements(existingSerialPorts).ToArray());

            #endregion UI_ELEMENTS            

            if (!File.Exists(LastParametersFileName))
                File.WriteAllText(LastParametersFileName, "COM1");

            var lastUsedPort = File.ReadAllLines("lastPort.txt");

            if (existingSerialPorts.Contains(lastUsedPort.FirstOrDefault()))
                UIElements.cmbBoxPortNumber.Text = lastUsedPort.FirstOrDefault();
            else
                UIElements.cmbBoxPortNumber.Text = "";
        }

        private void CommandButtonClick(object sender, EventArgs e)
        {
            var cmd = ((Button)sender).Tag.ToString();

            port.Write(cmd);
        }

        private void ConnectBtnClick(object sender, EventArgs e)
        {
            Controls.Cast<Control>().Where(x => x.Text == UIElements.btnConnect.Text).SingleOrDefault().Visible = false;
            Controls.Cast<Control>().Where(x => x.Text == UIElements.cmbBoxPortNumber.Text).SingleOrDefault().Visible = false;
            Controls.Cast<Control>().Where(x => x.Text == UIElements.btnOnD02.Text).SingleOrDefault().Visible = true;
            Controls.Cast<Control>().Where(x => x.Text == UIElements.btnOffD02.Text).SingleOrDefault().Visible = true;
            Controls.Cast<Control>().Where(x => x.Text == UIElements.btnOnD03.Text).SingleOrDefault().Visible = true;
            Controls.Cast<Control>().Where(x => x.Text == UIElements.btnOffD03.Text).SingleOrDefault().Visible = true;
            Controls.Cast<Control>().Where(x => x.Text == UIElements.btnOnD04.Text).SingleOrDefault().Visible = true;
            Controls.Cast<Control>().Where(x => x.Text == UIElements.btnOffD04.Text).SingleOrDefault().Visible = true;
            Controls.Cast<Control>().Where(x => x.Text == UIElements.btnOnD05.Text).SingleOrDefault().Visible = true;
            Controls.Cast<Control>().Where(x => x.Text == UIElements.btnOffD05.Text).SingleOrDefault().Visible = true;

            port = new SerialPort(((ComboBox)this.Controls[0]).SelectedItem.ToString(), 9600, Parity.None, 8);

            if (port.IsOpen)
                port.Close();

            port.Open();

            File.WriteAllText(LastParametersFileName, port.PortName);
        }
    }
}
