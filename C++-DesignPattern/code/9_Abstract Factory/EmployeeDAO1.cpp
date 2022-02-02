
class EmployeeDAO{
    
public:
    vector<EmployeeDO> GetEmployees(){
        SqlConnection* connection =
            new SqlConnection();
        connection->ConnectionString = "...";

        SqlCommand* command =
            new SqlCommand();
        command->CommandText="...";
        command->SetConnection(connection);

        SqlDataReader* reader = command->ExecuteReader();
        while (reader->Read()){

        }

    }
};
