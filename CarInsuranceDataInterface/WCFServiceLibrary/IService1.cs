using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace WCFServiceLibrary
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the interface name "IService1" in both code and config file together.
    [ServiceContract]
    public interface IService1
    {
        [OperationContract]
        string GetData(int value);

        [OperationContract]
        CompositeType GetDataUsingDataContract(CompositeType composite);

        // TODO: Add your service operations here
        [OperationContract]
        bool AddCustomer(CustomerDetails customer);

        [OperationContract]
        List<CustomerDetails> GetAllCustomers();

        [OperationContract]
        bool DeleteCustomer(CustomerDetails customerId);

        [OperationContract]
        List<CustomerDetails> SearchCustomers(CustomerDetails returnedCustomer);

        [OperationContract]
        bool UpdateCustomer(CustomerDetails customer);
    }

    // Use a data contract as illustrated in the sample below to add composite types to service operations.
    // You can add XSD files into the project. After building the project, you can directly use the data types defined there, with the namespace "WCFServiceLibrary.ContractType".
    [DataContract]
    public class CompositeType
    {
        bool boolValue = true;
        string stringValue = "Hello ";

        [DataMember]
        public bool BoolValue
        {
            get { return boolValue; }
            set { boolValue = value; }
        }

        [DataMember]
        public string StringValue
        {
            get { return stringValue; }
            set { stringValue = value; }
        }
    }

    [DataContract]
    public class CustomerDetails
    {
        int Id;
        string firstName;
        string lastName;
        string regDate;
        string houseNo;
        string streetName;
        string townCity;
        string postCode;
        string carMake;
        string carModel;
        string prodYear;

        [DataMember]
        public int ID
        {
            get { return Id; }
            set { Id = value; }
        }

        [DataMember]
        public string FirstName
        {
            get { return firstName; }
            set { firstName = value; }
        }

        [DataMember]
        public string LastName
        {
            get { return lastName; }
            set { lastName = value; }
        }

        [DataMember]
        public string RegDate
        {
            get { return regDate; }
            set { regDate = value; }
        }

        [DataMember]
        public string HouseNo
        {
            get { return houseNo; }
            set { houseNo = value; }
        }

        [DataMember]
        public string StreetName
        {
            get { return streetName; }
            set { streetName = value; }
        }

        [DataMember]
        public string TownCity
        {
            get { return townCity; }
            set { townCity = value; }
        }

        [DataMember]
        public string PostCode
        {
            get { return postCode; }
            set { postCode = value; }
        }

        [DataMember]
        public string CarMake
        {
            get { return carMake; }
            set { carMake = value; }
        }

        [DataMember]
        public string CarModel
        {
            get { return carModel; }
            set { carModel = value; }
        }

        [DataMember]
        public string ProdYear
        {
            get { return prodYear; }
            set { prodYear = value; }
        }
    }
}
