using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace WCFServiceLibrary
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "Service1" in both code and config file together.
    public class Service1 : IService1
    {
        public string GetData(int value)
        {
            return string.Format("You entered: {0}", value);
        }

        public CompositeType GetDataUsingDataContract(CompositeType composite)
        {
            if (composite == null)
            {
                throw new ArgumentNullException("composite");
            }
            if (composite.BoolValue)
            {
                composite.StringValue += "Suffix";
            }
            return composite;
        }
        private static MySqlConnection GetConnection()
        {
            // this method will return a connection to Azure MySQL constructed by connection string
            string myConnectionString = "Server=cidisqlserver.mysql.database.azure.com;User Id=mysqladmin;Password=Admin123;Database=customers;SslMode=Required;SslCa=DigiCertGlobalRootCA.crt";
            MySqlConnection connection = new MySqlConnection(myConnectionString);
            return connection;
        }

        public bool AddCustomer(CustomerDetails customer)
        {
            try
            {
                MySqlConnection connection = GetConnection();
                connection.Open();

                MySqlCommand cmd = new MySqlCommand("", connection);
                cmd.Prepare();
                cmd.CommandText = String.Format("insert into customers(firstname,lastname,regdate,houseno,streetname,towncity,postcode,carmake,carmodel,prodyear) values (?firstname_para,?lastname_para,?regdate_para,?houseno_para,?streetname_para,?towncity_para,?postcode_para,?carmake_para,?carmodel_para,?prodyear_para)");
                cmd.Parameters.AddWithValue("?firstname_para", customer.FirstName);
                cmd.Parameters.AddWithValue("?lastname_para", customer.LastName);
                cmd.Parameters.AddWithValue("?regdate_para", customer.RegDate);
                cmd.Parameters.AddWithValue("?houseno_para", customer.HouseNo);
                cmd.Parameters.AddWithValue("?streetname_para", customer.StreetName);
                cmd.Parameters.AddWithValue("?postcode_para", customer.PostCode);
                cmd.Parameters.AddWithValue("?towncity_para", customer.TownCity);
                cmd.Parameters.AddWithValue("?carmake_para", customer.CarMake);
                cmd.Parameters.AddWithValue("?carmodel_para", customer.CarModel);
                cmd.Parameters.AddWithValue("?prodyear_para", customer.ProdYear);
                cmd.ExecuteNonQuery();

                connection.Close();

                return true;
            }
            catch
            {
                return false;
            }
        }
        public List<CustomerDetails> GetAllCustomers()
        {
            List<CustomerDetails> customers = new List<CustomerDetails>();

            // Open connection
            MySqlConnection connection = GetConnection();
            connection.Open();

            // SQL query assignment
            MySqlCommand cmd = new MySqlCommand("select * from customers", connection);

            // Execute SQL query
            MySqlDataReader dataReader = cmd.ExecuteReader();
            while (dataReader.Read())
            {
                if (dataReader.HasRows)
                {
                    CustomerDetails customer = new CustomerDetails();

                    // read each column and assign value to corresponding property of Customer
                    customer.ID = dataReader.GetInt32("id");
                    customer.FirstName = dataReader.GetString("firstname");
                    customer.LastName = dataReader.GetString("lastname");
                    customer.RegDate = dataReader.GetString("regdate");
                    customer.HouseNo = dataReader.GetString("houseno");
                    customer.StreetName = dataReader.GetString("streetname");
                    customer.TownCity = dataReader.GetString("towncity");
                    customer.PostCode = dataReader.GetString("postcode");
                    customer.CarMake = dataReader.GetString("carmake");
                    customer.CarModel = dataReader.GetString("carmodel");
                    customer.ProdYear = dataReader.GetString("prodyear");

                    //add this employee to the list
                    customers.Add(customer);
                }
            }
            dataReader.Close();
            connection.Close();

            return customers;
        }

        public bool DeleteCustomer(CustomerDetails customerId)
        {
            try
            {
                // Open connection
                MySqlConnection connection = GetConnection();
                connection.Open();

                // SQL query assignment
                MySqlCommand cmd = new MySqlCommand("", connection);
                cmd.Prepare();
                cmd.CommandText = String.Format("delete from customers where id=?id_para");
                cmd.Parameters.AddWithValue("?id_para", customerId.ID);
                cmd.ExecuteNonQuery();

                connection.Close();
                return true;
            }

            catch
            {
                return false;
            }
        }

        public List<CustomerDetails> SearchCustomers(CustomerDetails returnedCustomer)
        {
            List<CustomerDetails> customers = new List<CustomerDetails>();

            // Open connection
            MySqlConnection connection = GetConnection();
            connection.Open();

            string searchQuery = null;

            string stringID = returnedCustomer.ID.ToString();
            if (returnedCustomer.ID != 0)
            {
                searchQuery += "select * from customers where id like ?id_para";
                //// SQL query assignment
                //MySqlCommand cmd = new MySqlCommand("select * from customers where id like ?id_para", connection);
                //// replace parameter "?firstname_para" with value of FirstName
                //cmd.Parameters.AddWithValue("?id_para", "%" + returnedCustomer.ID + "%");
                //// execute query
                //MySqlDataReader dataReader = cmd.ExecuteReader();
                //while (dataReader.Read())
                //{
                //    if (dataReader.HasRows)
                //    {
                //        CustomerDetails customer = new CustomerDetails();
                //        // read each column and assign value to corresponding property of customer
                //        customer.ID = dataReader.GetInt32("id");
                //        customer.FirstName = dataReader.GetString("firstname");
                //        customer.LastName = dataReader.GetString("lastname");
                //        customer.RegDate = dataReader.GetString("regdate");
                //        customer.HouseNo = dataReader.GetString("houseno");
                //        customer.StreetName = dataReader.GetString("streetname");
                //        customer.TownCity = dataReader.GetString("towncity");
                //        customer.PostCode = dataReader.GetString("postcode");
                //        customer.CarMake = dataReader.GetString("carmake");
                //        customer.CarModel = dataReader.GetString("carmodel");
                //        customer.ProdYear = dataReader.GetString("prodyear");
                //        // add this customer to the list
                //        customers.Add(customer);
                //    }
                //}
                //dataReader.Close();
            }

            if (returnedCustomer.FirstName != String.Empty)
            {
                if (searchQuery == null)
                    searchQuery += "select * from customers where firstname like ?firstname_para";
                else
                    searchQuery += " and firstname like ?firstname_para";
                //// SQL query assignment
                //MySqlCommand cmd = new MySqlCommand("select * from customers where firstname like ?firstname_para", connection);
                //// replace parameter "?firstname_para" with value of FirstName
                //cmd.Parameters.AddWithValue("?firstname_para", "%" + returnedCustomer.FirstName + "%");
                //// execute query
                //MySqlDataReader dataReader = cmd.ExecuteReader();
                //while (dataReader.Read())
                //{
                //    if (dataReader.HasRows)
                //    {
                //        CustomerDetails customer = new CustomerDetails();
                //        // read each column and assign value to corresponding property of customer
                //        customer.ID = dataReader.GetInt32("id");
                //        customer.FirstName = dataReader.GetString("firstname");
                //        customer.LastName = dataReader.GetString("lastname");
                //        customer.RegDate = dataReader.GetString("regdate");
                //        customer.HouseNo = dataReader.GetString("houseno");
                //        customer.StreetName = dataReader.GetString("streetname");
                //        customer.TownCity = dataReader.GetString("towncity");
                //        customer.PostCode = dataReader.GetString("postcode");
                //        customer.CarMake = dataReader.GetString("carmake");
                //        customer.CarModel = dataReader.GetString("carmodel");
                //        customer.ProdYear = dataReader.GetString("prodyear");
                //        // add this customer to the list
                //        customers.Add(customer);
                //    }
                //}
                //dataReader.Close();
            }

            if (returnedCustomer.LastName != String.Empty)
            {
                if (searchQuery == null)
                    searchQuery += "select * from customers where lastname like ?lastname_para";
                else
                    searchQuery += " and lastname like ?lastname_para;";
                //// SQL query assignment
                //MySqlCommand cmd = new MySqlCommand("select * from customers where lastname like ?lastname_para", connection);
                //// replace parameter "?lastname_para" with value of LastName
                //cmd.Parameters.AddWithValue("?lastname_para", "%" + returnedCustomer.LastName + "%");
                //// execute query
                //MySqlDataReader dataReader = cmd.ExecuteReader();
                //while (dataReader.Read())
                //{
                //    if (dataReader.HasRows)
                //    {
                //        CustomerDetails customer = new CustomerDetails();
                //        // read each column and assign value to corresponding property of customer
                //        customer.ID = dataReader.GetInt32("id");
                //        customer.FirstName = dataReader.GetString("firstname");
                //        customer.LastName = dataReader.GetString("lastname");
                //        customer.RegDate = dataReader.GetString("regdate");
                //        customer.HouseNo = dataReader.GetString("houseno");
                //        customer.StreetName = dataReader.GetString("streetname");
                //        customer.TownCity = dataReader.GetString("towncity");
                //        customer.PostCode = dataReader.GetString("postcode");
                //        customer.CarMake = dataReader.GetString("carmake");
                //        customer.CarModel = dataReader.GetString("carmodel");
                //        customer.ProdYear = dataReader.GetString("prodyear");
                //        // add this customer to the list
                //        customers.Add(customer);
                //    }
                //}
                //dataReader.Close();
            }

            if (returnedCustomer.RegDate != null) // may require further investigation
            {
                if (searchQuery == null)
                    searchQuery += "select * from customers where regdate like ?regdate_para";
                else
                    searchQuery += " and regdate like ?regdate_para";
                //// SQL query assignment
                //MySqlCommand cmd = new MySqlCommand("select * from customers where regdate like ?regdate_para", connection);
                //// replace parameter "?regdate_para" with value of RegDate
                //cmd.Parameters.AddWithValue("?regdate_para", "%" + returnedCustomer.RegDate + "%");
                //// execute query
                //MySqlDataReader dataReader = cmd.ExecuteReader();
                //while (dataReader.Read())
                //{
                //    if (dataReader.HasRows)
                //    {
                //        CustomerDetails customer = new CustomerDetails();
                //        // read each column and assign value to corresponding property of customer
                //        customer.ID = dataReader.GetInt32("id");
                //        customer.FirstName = dataReader.GetString("firstname");
                //        customer.LastName = dataReader.GetString("lastname");
                //        customer.RegDate = dataReader.GetString("regdate");
                //        customer.HouseNo = dataReader.GetString("houseno");
                //        customer.StreetName = dataReader.GetString("streetname");
                //        customer.TownCity = dataReader.GetString("towncity");
                //        customer.PostCode = dataReader.GetString("postcode");
                //        customer.CarMake = dataReader.GetString("carmake");
                //        customer.CarModel = dataReader.GetString("carmodel");
                //        customer.ProdYear = dataReader.GetString("prodyear");
                //        // add this customer to the list
                //        customers.Add(customer);
                //    }
                //}
                //dataReader.Close();
            }

            if (returnedCustomer.HouseNo != String.Empty)
            {
                if (searchQuery == null)
                    searchQuery += "select * from customers where houseno like ?houseno_para";
                else
                    searchQuery += " and houseno like ?houseno_para";
                //// SQL query assignment
                //MySqlCommand cmd = new MySqlCommand("select * from customers where houseno like ?houseno_para", connection);
                //// replace parameter "?houseno_para" with value of HouseNo
                //cmd.Parameters.AddWithValue("?houseno_para", "%" + returnedCustomer.HouseNo + "%");
                //// execute query
                //MySqlDataReader dataReader = cmd.ExecuteReader();
                //while (dataReader.Read())
                //{
                //    if (dataReader.HasRows)
                //    {
                //        CustomerDetails customer = new CustomerDetails();
                //        // read each column and assign value to corresponding property of customer
                //        customer.ID = dataReader.GetInt32("id");
                //        customer.FirstName = dataReader.GetString("firstname");
                //        customer.LastName = dataReader.GetString("lastname");
                //        customer.RegDate = dataReader.GetString("regdate");
                //        customer.HouseNo = dataReader.GetString("houseno");
                //        customer.StreetName = dataReader.GetString("streetname");
                //        customer.TownCity = dataReader.GetString("towncity");
                //        customer.PostCode = dataReader.GetString("postcode");
                //        customer.CarMake = dataReader.GetString("carmake");
                //        customer.CarModel = dataReader.GetString("carmodel");
                //        customer.ProdYear = dataReader.GetString("prodyear");
                //        // add this customer to the list
                //        customers.Add(customer);
                //    }
                //}
                //dataReader.Close();
            }

            if (returnedCustomer.StreetName != String.Empty)
            {
                if (searchQuery == null)
                    searchQuery += "select * from customers where streetname like ?streetname_para";
                else
                    searchQuery += " and streetname like ?streetname_para";
                //// SQL query assignment
                //MySqlCommand cmd = new MySqlCommand("select * from customers where streetname like ?streetname_para", connection);
                //// replace parameter "?streetname_para" with value of StreetName
                //cmd.Parameters.AddWithValue("?streetname_para", "%" + returnedCustomer.StreetName + "%");
                //// execute query
                //MySqlDataReader dataReader = cmd.ExecuteReader();
                //while (dataReader.Read())
                //{
                //    if (dataReader.HasRows)
                //    {
                //        CustomerDetails customer = new CustomerDetails();
                //        // read each column and assign value to corresponding property of customer
                //        customer.ID = dataReader.GetInt32("id");
                //        customer.FirstName = dataReader.GetString("firstname");
                //        customer.LastName = dataReader.GetString("lastname");
                //        customer.RegDate = dataReader.GetString("regdate");
                //        customer.HouseNo = dataReader.GetString("houseno");
                //        customer.StreetName = dataReader.GetString("streetname");
                //        customer.TownCity = dataReader.GetString("towncity");
                //        customer.PostCode = dataReader.GetString("postcode");
                //        customer.CarMake = dataReader.GetString("carmake");
                //        customer.CarModel = dataReader.GetString("carmodel");
                //        customer.ProdYear = dataReader.GetString("prodyear");
                //        // add this customer to the list
                //        customers.Add(customer);
                //    }
                //}
                //dataReader.Close();
            }

            if (returnedCustomer.TownCity != String.Empty)
            {
                if (searchQuery == null)
                    searchQuery += "select * from customers where towncity like ?towncity_para";
                else
                    searchQuery += " and towncity like ?towncity_para";
                //// SQL query assignment
                //MySqlCommand cmd = new MySqlCommand("select * from customers where towncity like ?towncity_para", connection);
                //// replace parameter "?towncity_para" with value of TownCity
                //cmd.Parameters.AddWithValue("?towncity_para", "%" + returnedCustomer.TownCity + "%");
                //// execute query
                //MySqlDataReader dataReader = cmd.ExecuteReader();
                //while (dataReader.Read())
                //{
                //    if (dataReader.HasRows)
                //    {
                //        CustomerDetails customer = new CustomerDetails();
                //        // read each column and assign value to corresponding property of customer
                //        customer.ID = dataReader.GetInt32("id");
                //        customer.FirstName = dataReader.GetString("firstname");
                //        customer.LastName = dataReader.GetString("lastname");
                //        customer.RegDate = dataReader.GetString("regdate");
                //        customer.HouseNo = dataReader.GetString("houseno");
                //        customer.StreetName = dataReader.GetString("streetname");
                //        customer.TownCity = dataReader.GetString("towncity");
                //        customer.PostCode = dataReader.GetString("postcode");
                //        customer.CarMake = dataReader.GetString("carmake");
                //        customer.CarModel = dataReader.GetString("carmodel");
                //        customer.ProdYear = dataReader.GetString("prodyear");
                //        // add this customer to the list
                //        customers.Add(customer);
                //    }
                //}
                //dataReader.Close();
            }

            if (returnedCustomer.PostCode != String.Empty)
            {
                if (searchQuery == null)
                    searchQuery += "select * from customers where postcode like ?postcode_para";
                else
                    searchQuery += " and postcode like ?postcode_para";
                //// SQL query assignment
                //MySqlCommand cmd = new MySqlCommand("select * from customers where postcode like ?postcode_para", connection);
                //// replace parameter "?postcode_para" with value of PostCode
                //cmd.Parameters.AddWithValue("?postcode_para", "%" + returnedCustomer.PostCode + "%");
                //// execute query
                //MySqlDataReader dataReader = cmd.ExecuteReader();
                //while (dataReader.Read())
                //{
                //    if (dataReader.HasRows)
                //    {
                //        CustomerDetails customer = new CustomerDetails();
                //        // read each column and assign value to corresponding property of customer
                //        customer.ID = dataReader.GetInt32("id");
                //        customer.FirstName = dataReader.GetString("firstname");
                //        customer.LastName = dataReader.GetString("lastname");
                //        customer.RegDate = dataReader.GetString("regdate");
                //        customer.HouseNo = dataReader.GetString("houseno");
                //        customer.StreetName = dataReader.GetString("streetname");
                //        customer.TownCity = dataReader.GetString("towncity");
                //        customer.PostCode = dataReader.GetString("postcode");
                //        customer.CarMake = dataReader.GetString("carmake");
                //        customer.CarModel = dataReader.GetString("carmodel");
                //        customer.ProdYear = dataReader.GetString("prodyear");
                //        // add this customer to the list
                //        customers.Add(customer);
                //    }
                //}
                //dataReader.Close();
            }

            if (returnedCustomer.CarMake != String.Empty)
            {
                if (searchQuery == null)
                    searchQuery += "select * from customers where carmake like ?carmake_para";
                else
                    searchQuery += " and carmake like ?carmake_para";
                //// SQL query assignment
                //MySqlCommand cmd = new MySqlCommand("select * from customers where carmake like ?carmake_para", connection);
                //// replace parameter "?carmake_para" with value of CarMake
                //cmd.Parameters.AddWithValue("?carmake_para", "%" + returnedCustomer.CarMake + "%");
                //// execute query
                //MySqlDataReader dataReader = cmd.ExecuteReader();
                //while (dataReader.Read())
                //{
                //    if (dataReader.HasRows)
                //    {
                //        CustomerDetails customer = new CustomerDetails();
                //        // read each column and assign value to corresponding property of customer
                //        customer.ID = dataReader.GetInt32("id");
                //        customer.FirstName = dataReader.GetString("firstname");
                //        customer.LastName = dataReader.GetString("lastname");
                //        customer.RegDate = dataReader.GetString("regdate");
                //        customer.HouseNo = dataReader.GetString("houseno");
                //        customer.StreetName = dataReader.GetString("streetname");
                //        customer.TownCity = dataReader.GetString("towncity");
                //        customer.PostCode = dataReader.GetString("postcode");
                //        customer.CarMake = dataReader.GetString("carmake");
                //        customer.CarModel = dataReader.GetString("carmodel");
                //        customer.ProdYear = dataReader.GetString("prodyear");
                //        // add this customer to the list
                //        customers.Add(customer);
                //    }
                //}
                //dataReader.Close();
            }

            if (returnedCustomer.CarModel != String.Empty)
            {
                if (searchQuery == null)
                    searchQuery += "select * from customers where carmodel like ?carmodel_para";
                else
                    searchQuery += " and carmodel like ?carmodel_para";
                //// SQL query assignment
                //MySqlCommand cmd = new MySqlCommand("select * from customers where carmodel like ?carmodel_para", connection);
                //// replace parameter "?carmodel_para" with value of CarModel
                //cmd.Parameters.AddWithValue("?carmodel_para", "%" + returnedCustomer.CarModel + "%");
                //// execute query
                //MySqlDataReader dataReader = cmd.ExecuteReader();
                //while (dataReader.Read())
                //{
                //    if (dataReader.HasRows)
                //    {
                //        CustomerDetails customer = new CustomerDetails();
                //        // read each column and assign value to corresponding property of customer
                //        customer.ID = dataReader.GetInt32("id");
                //        customer.FirstName = dataReader.GetString("firstname");
                //        customer.LastName = dataReader.GetString("lastname");
                //        customer.RegDate = dataReader.GetString("regdate");
                //        customer.HouseNo = dataReader.GetString("houseno");
                //        customer.StreetName = dataReader.GetString("streetname");
                //        customer.TownCity = dataReader.GetString("towncity");
                //        customer.PostCode = dataReader.GetString("postcode");
                //        customer.CarMake = dataReader.GetString("carmake");
                //        customer.CarModel = dataReader.GetString("carmodel");
                //        customer.ProdYear = dataReader.GetString("prodyear");
                //        // add this customer to the list
                //        customers.Add(customer);
                //    }
                //}
                //dataReader.Close();
            }

            if (returnedCustomer.ProdYear != String.Empty)
            {
                if (searchQuery == null)
                    searchQuery += "select * from customers where prodyear like ?prodyear_para";
                else
                    searchQuery += " and prodyear like ?prodyear_para";
                //// SQL query assignment
                //MySqlCommand cmd = new MySqlCommand("select * from customers where prodyear like ?prodyear_para", connection);
                //// replace parameter "?prodyear_para" with value of ProdYear
                //cmd.Parameters.AddWithValue("?prodyear_para", "%" + returnedCustomer.ProdYear + "%");
                //// execute query
                //MySqlDataReader dataReader = cmd.ExecuteReader();
                //while (dataReader.Read())
                //{
                //    if (dataReader.HasRows)
                //    {
                //        CustomerDetails customer = new CustomerDetails();
                //        // read each column and assign value to corresponding property of customer
                //        customer.ID = dataReader.GetInt32("id");
                //        customer.FirstName = dataReader.GetString("firstname");
                //        customer.LastName = dataReader.GetString("lastname");
                //        customer.RegDate = dataReader.GetString("regdate");
                //        customer.HouseNo = dataReader.GetString("houseno");
                //        customer.StreetName = dataReader.GetString("streetname");
                //        customer.TownCity = dataReader.GetString("towncity");
                //        customer.PostCode = dataReader.GetString("postcode");
                //        customer.CarMake = dataReader.GetString("carmake");
                //        customer.CarModel = dataReader.GetString("carmodel");
                //        customer.ProdYear = dataReader.GetString("prodyear");
                //        // add this customer to the list
                //        customers.Add(customer);
                //    }
                //}
                //dataReader.Close();
            }

            // SQL query assignment
            MySqlCommand cmd = new MySqlCommand(searchQuery, connection);
            
            cmd.Parameters.AddWithValue("?id_para", "%" + returnedCustomer.ID + "%");
            cmd.Parameters.AddWithValue("?firstname_para", "%" + returnedCustomer.FirstName + "%");
            cmd.Parameters.AddWithValue("?lastname_para", "%" + returnedCustomer.LastName + "%");
            cmd.Parameters.AddWithValue("?regdate_para", "%" + returnedCustomer.RegDate + "%");
            cmd.Parameters.AddWithValue("?houseno_para", "%" + returnedCustomer.HouseNo + "%");
            cmd.Parameters.AddWithValue("?streetname_para", "%" + returnedCustomer.StreetName + "%");
            cmd.Parameters.AddWithValue("?postcode_para", "%" + returnedCustomer.PostCode + "%");
            cmd.Parameters.AddWithValue("?towncity_para", "%" + returnedCustomer.TownCity + "%");
            cmd.Parameters.AddWithValue("?carmake_para", "%" + returnedCustomer.CarMake + "%");
            cmd.Parameters.AddWithValue("?carmodel_para", "%" + returnedCustomer.CarModel + "%");
            cmd.Parameters.AddWithValue("?prodyear_para", "%" + returnedCustomer.ProdYear + "%");

            // execute query
            MySqlDataReader dataReader = cmd.ExecuteReader();
            while (dataReader.Read())
            {
                if (dataReader.HasRows)
                {
                    CustomerDetails customer = new CustomerDetails();
                    // read each column and assign value to corresponding property of customer
                    customer.ID = dataReader.GetInt32("id");
                    customer.FirstName = dataReader.GetString("firstname");
                    customer.LastName = dataReader.GetString("lastname");
                    customer.RegDate = dataReader.GetString("regdate");
                    customer.HouseNo = dataReader.GetString("houseno");
                    customer.StreetName = dataReader.GetString("streetname");
                    customer.TownCity = dataReader.GetString("towncity");
                    customer.PostCode = dataReader.GetString("postcode");
                    customer.CarMake = dataReader.GetString("carmake");
                    customer.CarModel = dataReader.GetString("carmodel");
                    customer.ProdYear = dataReader.GetString("prodyear");
                    // add this customer to the list
                    customers.Add(customer);
                }
            }
            dataReader.Close();

            return customers;
        }

        public bool UpdateCustomer(CustomerDetails customer)
        {
            try
            {
                // Open connection
                MySqlConnection connection = GetConnection();
                connection.Open();

                MySqlCommand cmd = new MySqlCommand("", connection);
                cmd.Prepare();
                cmd.CommandText = String.Format("update customers set firstname=?firstname_para,lastname=?lastname_para,regdate=?regdate_para,houseno=?houseno_para,streetname=?streetname_para,towncity=?towncity_para,postcode=?postcode_para,carmake=?carmake_para,carmodel=?carmodel_para,prodyear=?prodyear_para where id=?id_para");
                //replace parameter "?id_para" with value of id
                cmd.Parameters.AddWithValue("?id_para", customer.ID);

                cmd.Parameters.AddWithValue("?firstname_para", customer.FirstName);
                cmd.Parameters.AddWithValue("?lastname_para", customer.LastName);
                cmd.Parameters.AddWithValue("?regdate_para", customer.RegDate);
                cmd.Parameters.AddWithValue("?houseno_para", customer.HouseNo);
                cmd.Parameters.AddWithValue("?streetname_para", customer.StreetName);
                cmd.Parameters.AddWithValue("?postcode_para", customer.PostCode);
                cmd.Parameters.AddWithValue("?towncity_para", customer.TownCity);
                cmd.Parameters.AddWithValue("?carmake_para", customer.CarMake);
                cmd.Parameters.AddWithValue("?carmodel_para", customer.CarModel);
                cmd.Parameters.AddWithValue("?prodyear_para", customer.ProdYear);
                cmd.ExecuteNonQuery();

                connection.Close();

                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}
