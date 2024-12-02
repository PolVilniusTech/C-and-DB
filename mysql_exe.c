/* Simple C program that connect to MariaDB Database Server */
/* sudo apt-get install default-libmysqlclient-dev -y */
/* gcc -o mysql_exe -L/usr/lib/mysql -I/usr/include/mysql mysql_exe.c -lmysqlclient */

#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include </usr/include/mariadb/mysql.h>

#define SELECT_SAMPLE "SELECT i1, i2, i3, i4 FROM test101 WHERE !SLEEP(10)"

int main(int argc, char **argv) 
{
	MYSQL		*conn;
	MYSQL_STMT	*stmt;
	MYSQL_BIND	bind[4];
	MYSQL_RES	*res;
	MYSQL_ROW	row;
	int 		j, m;
	int		row_count;
	int		int_data, int_data2, int_data3, int_data4;
	unsigned long	length[4];
	my_bool		is_null[4];
	my_bool		error[4];

	char *server = "localhost";
	char *user = "test";
	char *password = "password";
	char *database = "test";

	conn = mysql_init(NULL);

	if(!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) 
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);		
	}

	mysql_query(conn, "SHOW TABLES");

	res = mysql_use_result(conn);

	printf("MySQL Tables in MariaDB Database:\n");
	while((row = mysql_fetch_row(res)) != NULL)
		printf("%s \n", row[0]);
	
	mysql_free_result(res);

	puts("\nCreating sample:\n");
	mysql_query(conn, "DROP TABLE IF EXISTS test101");

	mysql_query(conn, "CREATE TABLE test101 (i1 int,i2 int,i3 int,i4 int,i5 int,i6 int,i7 int,i8 int,i9 int,i10 int,i11 int,i12 int,i13 int,i14 int,i15 int,i16 int,i17 int,i18 int,i19 int,i20 int,i21 int,i22 int,i23 int,i24 int,i25 int,i26 int,i27 int,i28 int,i29 int,i30 int,i31 int,i32 int,i33 int,i34 int,i35 int,i36 int,i37 int,i38 int,i39 int,i40 int,i41 int,i42 int,i43 int,i44 int,i45 int,i46 int,i47 int,i48 int,i49 int,i50 int,i51 int,i52 int,i53 int,i54 int,i55 int,i56 int,i57 int,i58 int,i59 int,i60 int,i61 int,i62 int,i63 int,i64 int,i65 int,i66 int,i67 int,i68 int,i69 int,i70 int,i71 int,i72 int,i73 int,i74 int,i75 int,i76 int,i77 int,i78 int,i79 int,i80 int,i81 int,i82 int,i83 int,i84 int,i85 int,i86 int,i87 int,i88 int,i89 int,i90 int,i91 int,i92 int,i93 int,i94 int,i95 int,i96 int,i97 int,i98 int,i99 int,i100 int)");
	
	mysql_query(conn, "INSERT INTO test101 value (1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100)");

	mysql_query(conn, "INSERT INTO test101 value (100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1)");

	stmt = mysql_stmt_init(conn);
	if (!stmt)
	{
		fprintf(stderr, " mysql_stmt_init(), out of memory\n");
		exit(0);
	}

	if (mysql_stmt_prepare(stmt, SELECT_SAMPLE, strlen(SELECT_SAMPLE)))
	{
		fprintf(stderr, " mysql_stmt_prepare(), SELECT failed\n");
		fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
		exit(0);
	} else {
		fprintf(stdout, "prepare, SELECT successful\n");
	}

	memset(bind, 0, sizeof(bind));
	
	/* INTEGER COLUMN */
	bind[0].buffer_type= MYSQL_TYPE_LONG;
	bind[0].buffer= (char *)&int_data;
	bind[0].is_null= &is_null[0];
	bind[0].length= &length[0];
	bind[0].error= &error[0];
	
	/* INTEGER COLUMN */
	bind[1].buffer_type= MYSQL_TYPE_LONG;
	bind[1].buffer= (char *)&int_data2;
	bind[1].is_null= &is_null[1];
	bind[1].length= &length[1];
	bind[1].error= &error[1];
	
	/* INTEGER COLUMN */
	bind[2].buffer_type= MYSQL_TYPE_LONG;
	bind[2].buffer= (char *)&int_data3;
	bind[2].is_null= &is_null[2];
	bind[2].length= &length[2];
	bind[2].error= &error[2];
	
	/* INTEGER COLUMN */
	bind[3].buffer_type= MYSQL_TYPE_LONG;
	bind[3].buffer= (char *)&int_data4;
	bind[3].is_null= &is_null[3];
	bind[3].length= &length[3];
	bind[3].error= &error[3];

	/* Bind the result buffers */
	if (mysql_stmt_bind_result(stmt, bind))
	{
		fprintf(stderr, " mysql_stmt_bind_result() failed\n");
		fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
		exit(0);
	}

	for (j=0; j<3; j++) {
		m=j+1;
		if (mysql_stmt_execute(stmt))
		{
			fprintf(stderr, " mysql_stmt_execute(), failed\n");
			fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
		} else {
			if (mysql_stmt_store_result(stmt))
			{
	  			fprintf(stderr, " mysql_stmt_store_result() failed\n");
	  			fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
	  			exit(0);
			}

      			/* Fetch all rows */
      			row_count= 0;
      			fprintf(stdout, "Fetching results No. %d ...\n", m);
			while (!mysql_stmt_fetch(stmt))
			{
				row_count++;
				fprintf(stdout, "  row %d\n", row_count);

	  			/* column 1 */
	  			fprintf(stdout, "   column1 (integer)  : ");
	  			if (is_null[0])
				{
					fprintf(stdout, " NULL\n");
				} else {
					fprintf(stdout, " %d(%ld)\n", int_data, length[0]);
				}
				
				/* column 2 */
				fprintf(stdout, "   column2 (integer)  : ");
	  			if (is_null[1])
				{
					fprintf(stdout, " NULL\n");
				} else {
					fprintf(stdout, " %d(%ld)\n", int_data2, length[1]);
				}

	  			/* column 3 */
				fprintf(stdout, "   column3 (integer)  : ");
	  			if (is_null[2])
				{
					fprintf(stdout, " NULL\n");
				} else {
					fprintf(stdout, " %d(%ld)\n", int_data3, length[2]);
				}
				
	 			/* column 4 */
				fprintf(stdout, "   column4 (integer)  : ");
	  			if (is_null[3])
				{
					fprintf(stdout, " NULL\n");
				} else {
					fprintf(stdout, " %d(%ld)\n", int_data4, length[3]);
				}
			}

      			/* Validate rows fetched */
      			fprintf(stdout, " total rows fetched: %d\n", row_count);
      			if (row_count != 2)
			{
	  			fprintf(stderr, " MySQL failed to return all rows\n");
	  			exit(0);
			}
    		}
  	}

	puts("closing connection\n");
	mysql_close(conn);
}
