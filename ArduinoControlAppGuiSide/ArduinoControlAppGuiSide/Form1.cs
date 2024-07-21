using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ArduinoControlAppGuiSide
{
    public partial class Form1 : Form
    {

        Button btnOnD02 = new Button();
        Button btnOffD02 = new Button();
        Button btnOnD03 = new Button();
        Button btnOffD03 = new Button();
        Button btnOnD04 = new Button();
        Button btnOffD04 = new Button();
        Button btnOnD05 = new Button();
        Button btnOffD05 = new Button();


        public Form1()
        {
            this.btnOnD02.Click += new System.EventHandler(this.btn5reset_spragtelejimas);
            this.btnOffD02.Click += new System.EventHandler(this.btn5reset_spragtelejimas);
            this.btnOnD03.Click += new System.EventHandler(this.btn5reset_spragtelejimas);
            this.btnOffD03.Click += new System.EventHandler(this.btn5reset_spragtelejimas);
            this.btnOnD04.Click += new System.EventHandler(this.btn5reset_spragtelejimas);
            this.btnOffD04.Click += new System.EventHandler(this.btn5reset_spragtelejimas);
            this.btnOnD05.Click += new System.EventHandler(this.btn5reset_spragtelejimas);
            this.btnOffD05.Click += new System.EventHandler(this.btn5reset_spragtelejimas);


            InitializeComponent();

            btnOnD02.Left = 20;
            btnOnD02.Top = 30;
            btnOnD02.Height = 20;
            btnOnD02.Width = 70;
            btnOnD02.Text = "D02 ON";
            btnOnD02.Visible = true;
            btnOnD02.Tag = "CMD_SET_ON_d2_pin";
            this.Controls.Add(btnOnD02);

            btnOffD02.Left = 100;
            btnOffD02.Top = 30;
            btnOffD02.Height = 20;
            btnOffD02.Width = 70;
            btnOffD02.Text = "D02 OFF";
            btnOffD02.Visible = true;
            btnOffD02.Tag = "CMD_SET_OFF_d2_pin";
            this.Controls.Add(btnOffD02);

            btnOnD03.Left = 20;
            btnOnD03.Top = 60;
            btnOnD03.Height = 20;
            btnOnD03.Width = 70;
            btnOnD03.Text = "D03 ON";
            btnOnD03.Visible = true;
            btnOnD03.Tag = "CMD_SET_ON_d3_pin";
            this.Controls.Add(btnOnD03);

            btnOffD03.Left = 100;
            btnOffD03.Top = 60;
            btnOffD03.Height = 20;
            btnOffD03.Width = 70;
            btnOffD03.Text = "D03 OFF";
            btnOffD03.Visible = true;
            btnOffD03.Tag = "CMD_SET_OFF_d3_pin";
            this.Controls.Add(btnOffD03);

            btnOnD04.Left = 20;
            btnOnD04.Top = 90;
            btnOnD04.Height = 20;
            btnOnD04.Width = 70;
            btnOnD04.Text = "D04 ON";
            btnOnD04.Visible = true;
            btnOnD04.Tag = "CMD_SET_ON_d4_pin";
            this.Controls.Add(btnOnD04);

            btnOffD04.Left = 100;
            btnOffD04.Top = 90;
            btnOffD04.Height = 20;
            btnOffD04.Width = 70;
            btnOffD04.Text = "D04 OFF";
            btnOffD04.Visible = true;
            btnOffD04.Tag = "CMD_SET_OFF_d4_pin";
            this.Controls.Add(btnOffD04);

            btnOnD05.Left = 20;
            btnOnD05.Top = 120;
            btnOnD05.Height = 20;
            btnOnD05.Width = 70;
            btnOnD05.Text = "D05 ON";
            btnOnD05.Visible = true;
            btnOnD05.Tag = "CMD_SET_ON_d5_pin";
            this.Controls.Add(btnOnD05);

            btnOffD05.Left = 100;
            btnOffD05.Top = 120;
            btnOffD05.Height = 20;
            btnOffD05.Width = 70;
            btnOffD05.Text = "D05 OFF";
            btnOffD05.Visible = true;
            btnOffD05.Tag = "CMD_SET_OFF_d5_pin";
            this.Controls.Add(btnOffD05);
        }

        private void btn5reset_spragtelejimas(object sender, EventArgs e)
        {
            var cmd = ((Button)sender).Tag.ToString();

            MessageBox.Show(cmd);
        }
    }
}
