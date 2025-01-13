using CarInsuranceDataInterface.WCFServiceReference;
using MySql.Data.MySqlClient;
using MySqlX.XDevAPI;
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
    public partial class UC_AllCustomers : UserControl
    {
        WCFServiceReference.Service1Client client = new WCFServiceReference.Service1Client();

        private int count;
        List<CustomerDetails> customerList;
        public UC_AllCustomers()
        {
            InitializeComponent();
            
            LoadCustomers();
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

        private void LoadCustomers()
        {
            customerList = client.GetAllCustomers().ToList();

            count = 0;
            NextButton.Enabled = false;
            PreviousButton.Enabled = false;

            if (count != customerList.Count())
            {
                IDTextBox.Text = customerList[0].ID.ToString();
                FirstNameTextBox.Text = customerList[0].FirstName;
                LastNameTextBox.Text = customerList[0].LastName;
                RegDatePicker.Text = customerList[0].RegDate;
                HouseNoTextBox.Text = customerList[0].HouseNo;
                StreetTextBox.Text = customerList[0].StreetName;
                TownTextBox.Text = customerList[0].TownCity;
                PostcodeTextBox.Text = customerList[0].PostCode;
                CarMakeTextBox.Text = customerList[0].CarMake;
                CarModelTextBox.Text = customerList[0].CarModel;
                YearTextBox.Text = customerList[0].ProdYear;
            }

            if (count + 1 != customerList.Count())
            {
                NextButton.Enabled = true;
            }
        }

        private void ViewCurrentCustomer(int index)
        {   
            IDTextBox.Text = customerList[index].ID.ToString();
            FirstNameTextBox.Text = customerList[index].FirstName;
            LastNameTextBox.Text = customerList[index].LastName;
            RegDatePicker.Text = customerList[index].RegDate;
            HouseNoTextBox.Text = customerList[index].HouseNo;
            StreetTextBox.Text = customerList[index].StreetName;
            TownTextBox.Text = customerList[index].TownCity;
            PostcodeTextBox.Text = customerList[index].PostCode;
            CarMakeTextBox.Text = customerList[index].CarMake;
            CarModelTextBox.Text = customerList[index].CarModel;
            YearTextBox.Text = customerList[index].ProdYear;
        }

        private void UpdateButton_Click(object sender, EventArgs e)
        {
            if (!DataValidation())
            {
                MessageBox.Show("One or more fields have invalid or empty data. Please check all fields and try again.",
                     "Data Validation Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                DialogResult result = MessageBox.Show("You are going to update the customer details associated with the displayed ID. Do you wish to continue?",
                         "Update Warning", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
                
                if (result == DialogResult.OK)
                {
                    WCFServiceReference.CustomerDetails updateCustomer = new WCFServiceReference.CustomerDetails();

                    updateCustomer.ID = Int32.Parse(IDTextBox.Text);
                    updateCustomer.FirstName = FirstNameTextBox.Text;
                    updateCustomer.LastName = LastNameTextBox.Text;
                    updateCustomer.RegDate = RegDatePicker.Value.ToShortDateString();
                    updateCustomer.HouseNo = HouseNoTextBox.Text;
                    updateCustomer.StreetName = StreetTextBox.Text;
                    updateCustomer.TownCity = TownTextBox.Text;
                    updateCustomer.PostCode = PostcodeTextBox.Text;
                    updateCustomer.CarMake = CarMakeTextBox.Text;
                    updateCustomer.CarModel = CarModelTextBox.Text;
                    updateCustomer.ProdYear = YearTextBox.Text;
                    bool updateSuccess = client.UpdateCustomer(updateCustomer);

                    if (updateSuccess)
                    {
                        MessageBox.Show("Customer has been successfully updated.",
                         "Update Customer success", MessageBoxButtons.OK, MessageBoxIcon.Information);

                        LoadCustomers();
                    }
                    else
                    {
                        MessageBox.Show("Failed to update customer. Please try again later.",
                     "Update Customer error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
            }
        }

        private void DeleteButton_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("You are going to delete the customer associated with the displayed ID. Do you wish to continue?",
                         "Delete Warning", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);

            if (result == DialogResult.OK)
            {
                WCFServiceReference.CustomerDetails deleteCustomer = new WCFServiceReference.CustomerDetails();

                deleteCustomer.ID = Int32.Parse(IDTextBox.Text);
                bool deleteSuccess = client.DeleteCustomer(deleteCustomer);

                if (deleteSuccess)
                {
                    MessageBox.Show("Customer has been successfully deleted.",
                     "Delete Customer success", MessageBoxButtons.OK, MessageBoxIcon.Information);

                    LoadCustomers();
                }
                else
                {
                    MessageBox.Show("Failed to delete customer. Please try again later.",
                 "Delete Customer error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

        private void PreviousButton_Click(object sender, EventArgs e)
        {
            if (count - 1 >= 0)
            {
                count = count - 1;
                NextButton.Enabled = true;

                ViewCurrentCustomer(count);
            }

            if (count - 1 < 0)
            {
                PreviousButton.Enabled = false;
            }
        }

        private void NextButton_Click(object sender, EventArgs e)
        {
            if (count + 1 != customerList.Count())
            {
                count = count + 1;
                PreviousButton.Enabled = true;

                ViewCurrentCustomer(count);
            }

            if (count + 1 == customerList.Count())
            {
                NextButton.Enabled = false;
            }
        }
    }
}
