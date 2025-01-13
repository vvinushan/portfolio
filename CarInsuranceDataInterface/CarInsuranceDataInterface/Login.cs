using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CarInsuranceDataInterface
{
    public partial class Login : Form
    {
        private string connectionString;
        public Login()
        {
            InitializeComponent();
        }

        private void Login_Load(object sender, EventArgs e)
        {
            connectionString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=\"C:\\Users\\Vinushan\\Documents\\University UoL\\September 2023\\CO7215 Advanced Web Technologies\\CW\\CarInsuranceDataInterface\\CarInsuranceDataInterface\\UserDatabase.mdf\";Integrated Security=True";

        }

        private void LoginButton_Click(object sender, EventArgs e)
        {
            SqlConnection connection = new SqlConnection(connectionString);
            connection.Open();

            SqlCommand cmd = new SqlCommand("select * from login where username=@username_para and password=@password_para", connection);
            cmd.Parameters.AddWithValue("@username_para", UsernameTextBox.Text);
            cmd.Parameters.AddWithValue("@password_para", PasswordTextBox.Text);

            SqlDataReader dataReader = cmd.ExecuteReader();
            if (dataReader.Read())
            {
                dataReader.Close();
                this.Hide();
                CIDI myCIDI = new CIDI();
                myCIDI.ShowDialog();
            }
            else
            {
                MessageBox.Show("Account not found. For testing purposes, please read README.docx.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
