
public class Matrix {
	
	private int rowNum;
	private int colNum;
	private int data[][];
	
	public Matrix(int row, int col) {
		if (row <= 0 || col <= 0) {
			rowNum = 3;
			colNum = 3;
			data = new int[rowNum][colNum];
			for (int i=0;i<rowNum;i++) {
				for (int j=0;j<colNum;j++) {
					data[i][j] = 0;
				}
			}	
		} else {
			rowNum = row;
			colNum = col;
			data = new int[rowNum][colNum];
			for (int i=0;i<rowNum;i++) {
				for (int j=0;j<colNum;j++) {
					data[i][j] = 0;
				}
			}
		}
		
	}
	
	public Matrix(int table[][]) {
		rowNum = table.length;
		colNum = table[0].length;
		data = new int[rowNum][colNum];
		for (int i=0;i<rowNum;i++) {
			for (int j=0;j<colNum;j++) {
				data[i][j] = table[i][j];
			}
		}
	}
	
	public int getElement(int i, int j) throws IndexOutOfBoundsException {
		if (i<rowNum && j<colNum) {
			return data[i][j];
		} else {
			throw new IndexOutOfBoundsException("Invalid Indexes.");
		}
	}
	
	public boolean setElement(int x, int i, int j) {
		try {
			data[i][j] = x;
			return true;
		}
		catch(Exception e) {
			System.out.println(e);
			return false;
		}
	}
	
	public Matrix copy() {
		Matrix copied = new Matrix(this.data);
		return copied;
	}
	
	public void addTo(Matrix m) throws ArithmeticException {
		if (this.rowNum == m.rowNum && this.colNum == m.colNum) {
			for (int i=0;i<this.rowNum;i++) {
				for (int j=0;j<this.colNum;j++) {
					this.data[i][j] += m.data[i][j];
				}
			}
		} else {
			throw new ArithmeticException("Invalid operation");
		}
	}
	
	public Matrix subMatrix(int i, int j) throws IndexOutOfBoundsException {
		if (i<this.rowNum && j<this.colNum) {
			Matrix subMat = new Matrix(i,j);
			for (int x=0;x<subMat.rowNum;x++) {
				for (int y=0;y<subMat.colNum;y++) {
					subMat.data[x][y] = this.data[x][y];
				}
			}
			return subMat;
		} else {
			throw new IndexOutOfBoundsException("Submatrix not defined");
		}
	}
	
	public String toString() {
		String output = new String("");
		for (int i=0;i<rowNum;i++) {
			for (int j=0;j<colNum;j++) {
				output += data[i][j];
				output += "  ";
			}
			output += "\n";
		}
		return output;
	}
	
	public boolean isUpperTr() {
		for (int i=0;i<rowNum;i++) {
			for (int j=0;j<colNum;j++) {
				if (i>j && data[i][j]!=0) {return false;}
			}
		}
		return true;
	}
	
	public static Matrix sum(Matrix[] matArray) {
		Matrix sum = new Matrix(matArray[0].rowNum,matArray[0].colNum);
		
		try {
			for (int i=0;i<matArray.length;i++) {
				sum.addTo(matArray[i]);
			}
		} catch (ArithmeticException e) {
			System.out.println(e);
		}
		
		return sum;
	}
	
	public int getRows() {
		return rowNum;
	}
	
	public int getCols() {
		return colNum;
	}
	
	public static void main(String[] args) {
//		Matrix test = new Matrix(5,5);
		int arr[][] = {{5,4,6},{4,2,3},{6,8,7},{3,4,5}};
		int upper[][] = {{5,4,6},{0,2,3},{0,0,7}};
		Matrix test2 = new Matrix(arr);
		Matrix upperTest = new Matrix(upper);
		Matrix test3;
		System.out.println(test2.isUpperTr());
		System.out.println(upperTest.isUpperTr());
		System.out.println(test2.toString());
		
//		System.out.println(test2.getElement(2,1));
//		System.out.println(test2.setElement(4,2,44));
		test3 = test2.copy();
//		test3.setElement(2,0,1);
//		test3.addTo(test2);
		Matrix test4 = test3.subMatrix(2,2);
//		System.out.println(test4.toString());
		
		
	}
	
}