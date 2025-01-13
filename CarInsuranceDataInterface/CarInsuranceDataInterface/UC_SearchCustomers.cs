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
    public partial class UC_SearchCustomers : UserControl
    {
        WCFServiceReference.Service1Client client = new WCFServiceReference.Service1Client();

        private int count;
        List<WCFServiceReference.CustomerDetails> searchList;
        public UC_SearchCustomers()
        {
            InitializeComponent();
            RegDatePicker.Value = System.DateTime.Today;
            ResetFields();
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

        private void Search()
        {
            if ((IDTextBox.Text == String.Empty) && (FirstNameTextBox.Text == String.Empty) && (LastNameTextBox.Text == String.Empty) && (RegDatePickerCheckBox.Checked == false) && (HouseNoTextBox.Text == String.Empty) && (StreetTextBox.Text == String.Empty) && (TownTextBox.Text == String.Empty) && (PostcodeTextBox.Text == String.Empty) && (CarMakeTextBox.Text == String.Empty) && (CarModelTextBox.Text == String.Empty) && (YearTextBox.Text == String.Empty))
            {
                MessageBox.Show("All fields are empty. Please enter customer data to search.",
                 "Fields empty error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                SearchButton.Enabled = false;
                ResetButton.Enabled = true;
                DeleteButton.Enabled = true;
                UpdateButton.Enabled = true;

                IDTextBox.ReadOnly = true;

                count = 0;

                WCFServiceReference.CustomerDetails searchCustomer = new WCFServiceReference.CustomerDetails();

                if (IDTextBox.Text != String.Empty)
                    searchCustomer.ID = Int32.Parse(IDTextBox.Text);
                searchCustomer.FirstName = FirstNameTextBox.Text;
                searchCustomer.LastName = LastNameTextBox.Text;
                if (RegDatePickerCheckBox.Checked == true)
                    searchCustomer.RegDate = RegDatePicker.Value.ToShortDateString();
                searchCustomer.HouseNo = HouseNoTextBox.Text;
                searchCustomer.StreetName = StreetTextBox.Text;
                searchCustomer.TownCity = TownTextBox.Text;
                searchCustomer.PostCode = PostcodeTextBox.Text;
                searchCustomer.CarMake = CarMakeTextBox.Text;
                searchCustomer.CarModel = CarModelTextBox.Text;
                searchCustomer.ProdYear = YearTextBox.Text;

                searchList = client.SearchCustomers(searchCustomer).ToList();

                MessageBox.Show("Search Complete",
                     "Search Customers", MessageBoxButtons.OK, MessageBoxIcon.Information);

                if (count != searchList.Count())
                {
                    IDTextBox.Text = searchList[0].ID.ToString();
                    FirstNameTextBox.Text = searchList[0].FirstName;
                    LastNameTextBox.Text = searchList[0].LastName;
                    RegDatePicker.Text = searchList[0].RegDate;
                    HouseNoTextBox.Text = searchList[0].HouseNo;
                    StreetTextBox.Text = searchList[0].StreetName;
                    TownTextBox.Text = searchList[0].TownCity;
                    PostcodeTextBox.Text = searchList[0].PostCode;
                    CarMakeTextBox.Text = searchList[0].CarMake;
                    CarModelTextBox.Text = searchList[0].CarModel;
                    YearTextBox.Text = searchList[0].ProdYear;
                }

                if (count + 1 != searchList.Count())
                {
                    NextButton.Enabled = true;
                }
            }
        }

        private void ViewCurrentCustomer(int index)
        {
            IDTextBox.Text = searchList[index].ID.ToString();
            FirstNameTextBox.Text = searchList[index].FirstName;
            LastNameTextBox.Text = searchList[index].LastName;
            RegDatePicker.Text = searchList[index].RegDate;
            HouseNoTextBox.Text = searchList[index].HouseNo;
            StreetTextBox.Text = searchList[index].StreetName;
            TownTextBox.Text = searchList[index].TownCity;
            PostcodeTextBox.Text = searchList[index].PostCode;
            CarMakeTextBox.Text = searchList[index].CarMake;
            CarModelTextBox.Text = searchList[index].CarModel;
            YearTextBox.Text = searchList[index].ProdYear;
        }

        private void ResetFields()
        {
            IDTextBox.Text = String.Empty;
            FirstNameTextBox.Text = String.Empty;
            LastNameTextBox.Text = String.Empty;
            RegDatePicker.Enabled = false;
            HouseNoTextBox.Text = String.Empty;
            StreetTextBox.Text = String.Empty;
            TownTextBox.Text = String.Empty;
            PostcodeTextBox.Text = String.Empty;
            CarMakeTextBox.Text = String.Empty;
            CarModelTextBox.Text = String.Empty;
            YearTextBox.Text = String.Empty;

            ResetButton.Enabled = false;
            DeleteButton.Enabled = false;
            UpdateButton.Enabled = false;
            PreviousButton.Enabled = false;
            NextButton.Enabled = false;
            SearchButton.Enabled = true;
            IDTextBox.ReadOnly = false;
            RegDatePickerCheckBox.Checked = false;
        }
        private void ResetButton_Click(object sender, EventArgs e)
        {
            ResetFields();
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

                    ResetFields();
                }
                else
                {
                    MessageBox.Show("Failed to delete customer. Please try again later.",
                 "Delete Customer error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
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

                        ResetFields();
                    }
                    else
                    {
                        MessageBox.Show("Failed to update customer. Please try again later.",
                     "Update Customer error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
            }
        }

        private void SearchButton_Click(object sender, EventArgs e)
        {
            Search();
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
            if (count + 1 != searchList.Count())
            {
                count = count + 1;
                PreviousButton.Enabled = true;

                ViewCurrentCustomer(count);
            }

            if (count + 1 == searchList.Count())
            {
                NextButton.Enabled = false;
            }
        }

        private void RegDatePickerCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (RegDatePickerCheckBox.Checked)
            {
                RegDatePicker.Enabled = true;
            }
            else
            {
                RegDatePicker.Enabled = false;
            }
        }
    }
}
