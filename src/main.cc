
#include <string>
#include <occi.h>
#include <iostream>

using namespace oracle::occi;

int main(){


    const std::string userName = "HR";
    const std::string password = "password";
    const std::string connectString = "";

    Environment *env = Environment::createEnvironment();

    {
        Connection *conn = env->createConnection(
        userName, password, connectString);
        Statement *stmt = conn->createStatement("SELECT blobcol FROM mytable");
        ResultSet *rs = stmt->executeQuery();
        rs->next();
        Blob b = rs->getBlob(1);
        std::cout << "Length of BLOB : " << b.length() << std::endl;
        stmt->closeResultSet(rs);
        conn->terminateStatement(stmt);
        env->terminateConnection(conn);
    }

    Environment::terminateEnvironment(env);


    return 0;
}