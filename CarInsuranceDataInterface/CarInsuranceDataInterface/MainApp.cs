using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CarInsuranceDataInterface
{
    public partial class CIDI : Form
    {
        public CIDI()
        {
            InitializeComponent();
            HomeButtonPanel.BackColor = SystemColors.MenuHighlight;
            ChangeTabs(new UC_Home());
        }

        private void TurnOffTabs()
        {
            HomeButtonPanel.BackColor = SystemColors.ButtonFace;
            AllCustomersPanel.BackColor = SystemColors.ButtonFace;
            AddCustomerPanel.BackColor = SystemColors.ButtonFace;
            SearchCustomersPanel.BackColor = SystemColors.ButtonFace;
        }
        private void ChangeTabs(UserControl UC)
        {
            TabPanel.Controls.Clear();
            TabPanel.Controls.Add(UC);
            UC.Dock = DockStyle.Fill;
        }
        private void HomeButton_Click(object sender, EventArgs e)
        {
            TurnOffTabs();
            HomeButtonPanel.BackColor = SystemColors.MenuHighlight;
            ChangeTabs(new UC_Home());
        }

        private void AllCustomersButton_Click(object sender, EventArgs e)
        {
            TurnOffTabs();
            AllCustomersPanel.BackColor = SystemColors.MenuHighlight;
            ChangeTabs(new UC_AllCustomers());
        }

        private void AddCustomerButton_Click(object sender, EventArgs e)
        {
            TurnOffTabs();
            AddCustomerPanel.BackColor = SystemColors.MenuHighlight;
            ChangeTabs(new UC_AddCustomer());
        }

        private void SearchCustomersButton_Click(object sender, EventArgs e)
        {
            TurnOffTabs();
            SearchCustomersPanel.BackColor = SystemColors.MenuHighlight;
            ChangeTabs(new UC_SearchCustomers());
        }
    }
}
