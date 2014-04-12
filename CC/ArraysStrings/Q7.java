/*
	description: First glance, we can use O(M+N) space to save status of row and    column(those have zero element(s)). In second glance, what we need to do is     set those rows and columns with 0s if they are marked.

	Totally time complexity: O(M*N)
*/

public void setZerosInMatrix(int[][] matrix)
{
	boolean[] row = new boolean[matrix.length()];
	boolean[] column = new boolean[matrix[0].length()];

	//first glance
	for(int i = 0, i < matrix.length(); i++){
		for(int j = 0; j < matrix[0].length(); j++){
			if(matrix[i][j] == 0){
				row[i] = true;
				column[j] = true;
			}
		}
	}

	for(int i = 0; i < row.length(); i++){
		if(row[i] == true){
			for(int j = 0; j < column.length(); j++){
				matrix[i][j] = 0;
			}
		}
	}

    for(int j  = 0; i < column.length(); j++){
        if(colunm[j] == true){
            for(int i = 0; i < row.length(); i++){
                matrix[i][j] = 0;
            }
        }
    }
}
