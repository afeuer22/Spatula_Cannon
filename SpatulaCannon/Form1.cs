using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SpatulaCannon
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            port.Write("B");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            port.Write("F");
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            port.Open();
        }
    }
}
