using CarInsuranceDataInterface.WCFServiceReference;
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
    public partial class UC_AddCustomer : UserControl
    {
        WCFServiceReference.Service1Client client = new WCFServiceReference.Service1Client();
        public UC_AddCustomer()
        {
            InitializeComponent();
            RegDatePicker.Value = System.DateTime.Today;
        }

        private bool DataValidation()
        {
            if (String.IsNullOrEmpty(FirstNameTextBox.Text) || (FirstNameTextBox.Text).Contains(" "))
                return false;
            else if (String.IsNullOrWhiteSpace(LastNameTextBox.Text) || (LastNameTextBox.Text).Contains(" "))
                return false;
            else if (this.RegDatePicker.Value > System.DateTime.Today)
                return false;
            else if (String.IsNullOrWhiteSpace(HouseNoTextBox.Text) || (HouseNoTextBox.Text).Contains(" "))
                return false;
            else if (StreetTextBox.Text.Any(char.IsDigit) || TownTextBox.Text.Any(char.IsDigit) || (TownTextBox.Text).Contains(" "))
                return false;
            else if (String.IsNullOrEmpty(PostcodeTextBox.Text))
                return false;
            else if (String.IsNullOrEmpty(CarMakeTextBox.Text))
                return false;
            else if (String.IsNullOrEmpty(CarModelTextBox.Text))
                return false;
            else if (YearTextBox.Text.All(char.IsDigit) == false || (YearTextBox.Text).Contains(" ") || (YearTextBox.Text).Length > 4)
                return false;
            else
                return true;
        }
        private void ResetButton_Click(object sender, EventArgs e)
        {
            FirstNameTextBox.Text = String.Empty;
            LastNameTextBox.Text = String.Empty;
            RegDatePicker.Value = System.DateTime.Today;
            HouseNoTextBox.Text = String.Empty;
            StreetTextBox.Text = String.Empty;
            TownTextBox.Text = String.Empty;
            PostcodeTextBox.Text = String.Empty;
            CarMakeTextBox.Text = String.Empty;
            CarModelTextBox.Text = String.Empty;
            YearTextBox.Text = String.Empty;
        }

        private void AddCustomerButton_Click(object sender, EventArgs e)
        {
            if (!DataValidation())
            {
                MessageBox.Show("One or more fields have invalid or empty data. Please check all fields and try again.",
                     "Data Validation Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                DialogResult result = MessageBox.Show("Are you sure you want to add this customer?",
                         "Add Customer confirmation", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

                if (result == DialogResult.Yes)
                {
                    WCFServiceReference.CustomerDetails addCustomer = new WCFServiceReference.CustomerDetails();

                    addCustomer.FirstName = FirstNameTextBox.Text;
                    addCustomer.LastName = LastNameTextBox.Text;
                    addCustomer.RegDate = RegDatePicker.Value.ToShortDateString();
                    addCustomer.HouseNo = HouseNoTextBox.Text;
                    addCustomer.StreetName = StreetTextBox.Text;
                    addCustomer.TownCity = TownTextBox.Text;
                    addCustomer.PostCode = PostcodeTextBox.Text;
                    addCustomer.CarMake = CarMakeTextBox.Text;
                    addCustomer.CarModel = CarModelTextBox.Text;
                    addCustomer.ProdYear = YearTextBox.Text;
                    bool addSuccess = client.AddCustomer(addCustomer);

                    if (addSuccess)
                    {
                        MessageBox.Show("New customer has been successfully added.",
                         "Add Customer success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    }
                    else
                    {
                        MessageBox.Show("Failed to add customer. Please re-check all fields and try again.",
                     "Add customer error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
            }
        }
    }
}
