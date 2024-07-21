using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ArduinoControlAppGuiSide
{
    public static class UIElements
    {
        public static ComboBox cmbBoxPortNumber = new ComboBox(); 
        public static Button btnConnect = new Button();
        public static Button btnOnD02 = new Button();
        public static Button btnOffD02 = new Button();
        public static Button btnOnD03 = new Button();
        public static Button btnOffD03 = new Button();
        public static Button btnOnD04 = new Button();
        public static Button btnOffD04 = new Button();
        public static Button btnOnD05 = new Button();
        public static Button btnOffD05 = new Button();

        private static List<Control> uiControlsList = new List<Control>();

        public static List<Control> GenerateUIElements(string[] ports)
        {
            cmbBoxPortNumber.Left = 20;
            cmbBoxPortNumber.Top = 20;
            cmbBoxPortNumber.Height = 20;
            cmbBoxPortNumber.Width = 70;
            cmbBoxPortNumber.Visible = true;
            cmbBoxPortNumber.Tag = "";
            cmbBoxPortNumber.Items.AddRange(ports);
            uiControlsList.Add(cmbBoxPortNumber);

            btnConnect.Left = 120;
            btnConnect.Top = 20;
            btnConnect.Height = 20;
            btnConnect.Width = 70;
            btnConnect.Text = "Connect";
            btnConnect.Visible = true;
            btnConnect.Tag = "";
            uiControlsList.Add(btnConnect);

            btnOnD02.Left = 20;
            btnOnD02.Top = 50;
            btnOnD02.Height = 20;
            btnOnD02.Width = 70;
            btnOnD02.Text = "D02 ON";
            btnOnD02.Visible = false;
            btnOnD02.Tag = "CMD_SET_ON_d2_pin";
            uiControlsList.Add(btnOnD02);

            btnOffD02.Left = 100;
            btnOffD02.Top = btnOnD02.Top;
            btnOffD02.Height = 20;
            btnOffD02.Width = 70;
            btnOffD02.Text = "D02 OFF";
            btnOffD02.Visible = false;
            btnOffD02.Tag = "CMD_SET_OFF_d2_pin";
            uiControlsList.Add(btnOffD02);

            btnOnD03.Left = btnOnD02.Left;
            btnOnD03.Top = btnOnD02.Top + 30;
            btnOnD03.Height = btnOnD02.Height;
            btnOnD03.Width = btnOnD02.Width;
            btnOnD03.Text = "D03 ON";
            btnOnD03.Visible = false;
            btnOnD03.Tag = "CMD_SET_ON_d3_pin";
            uiControlsList.Add(btnOnD03);

            btnOffD03.Left = btnOffD02.Left;
            btnOffD03.Top = btnOffD02.Top + 30;
            btnOffD03.Height = btnOffD02.Height;
            btnOffD03.Width = btnOffD02.Width;
            btnOffD03.Text = "D03 OFF";
            btnOffD03.Visible = false;
            btnOffD03.Tag = "CMD_SET_OFF_d3_pin";
            uiControlsList.Add(btnOffD03);

            btnOnD04.Left = btnOnD02.Left;
            btnOnD04.Top = btnOnD03.Top + 30;
            btnOnD04.Height = btnOnD02.Height;
            btnOnD04.Width = btnOnD02.Width;
            btnOnD04.Text = "D04 ON";
            btnOnD04.Visible = false;
            btnOnD04.Tag = "CMD_SET_ON_d4_pin";
            uiControlsList.Add(btnOnD04);

            btnOffD04.Left = btnOffD02.Left;
            btnOffD04.Top = btnOffD03.Top + 30;
            btnOffD04.Height = btnOffD02.Height;
            btnOffD04.Width = btnOffD02.Width;
            btnOffD04.Text = "D04 OFF";
            btnOffD04.Visible = false;
            btnOffD04.Tag = "CMD_SET_OFF_d4_pin";
            uiControlsList.Add(btnOffD04);

            btnOnD05.Left = btnOnD02.Left;
            btnOnD05.Top = btnOnD04.Top + 30;
            btnOnD05.Height = btnOnD02.Height;
            btnOnD05.Width = btnOnD02.Width;
            btnOnD05.Text = "D05 ON";
            btnOnD05.Visible = false;
            btnOnD05.Tag = "CMD_SET_ON_d5_pin";
            uiControlsList.Add(btnOnD05);

            btnOffD05.Left = btnOffD02.Left;
            btnOffD05.Top = btnOffD04.Top + 30;
            btnOffD05.Height = btnOffD02.Height;
            btnOffD05.Width = btnOffD02.Width;
            btnOffD05.Text = "D05 OFF";
            btnOffD05.Visible = false;
            btnOffD05.Tag = "CMD_SET_OFF_d5_pin";
            uiControlsList.Add(btnOffD05);

            return uiControlsList;
        }
    }
}
