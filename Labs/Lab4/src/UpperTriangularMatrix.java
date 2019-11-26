
public class UpperTriangularMatrix {
	
	private int size;
	private int upMat[];

	public UpperTriangularMatrix(int n) {
		if (n<=0) {
			size = 1;
			upMat = new int[(n*(n+1)/2)];
		} else {
			size = n;
			upMat = new int[(n*(n+1)/2)];
		}
	}
	
	public UpperTriangularMatrix(Matrix upTriM) throws IllegalArgumentException {
		if (upTriM.isUpperTr() == true && upTriM.getRows() == upTriM.getCols()) {
			size = upTriM.getRows();
			int counter = 0;
			upMat = new int[(size*(size+1)/2)];
			for (int i=0;i<upTriM.getRows();i++) {
				for (int j=0;j<upTriM.getCols();j++) {
					if (j>=i) {
						upMat[counter] = upTriM.getElement(i, j);
						counter++;
					}
				}
			}
		} else {
			throw new IllegalArgumentException("Matrix not upper triangular or not square");
		}
		
	}
	
	public int getDim() {
		return size;
	}
	
	public int getElement(int i,int j) throws IndexOutOfBoundsException {
		if (i>=size || j>=size) {throw new IndexOutOfBoundsException("Invalid Indexes");}
			Matrix me = this.fullMatrix();
			return me.getElement(i, j);
			
	}
	
	public void setElement(int x, int i, int j) throws IndexOutOfBoundsException, IllegalArgumentException {
		if (i>=size || j>=size) {throw new IndexOutOfBoundsException("Invalid Indexes");}
		if (i>j) {throw new IllegalArgumentException("Invalid Operation");}
		Matrix temp = this.fullMatrix();
		temp.setElement(x, i, j);
		UpperTriangularMatrix temp2 = new UpperTriangularMatrix(temp);
		for(int h=0;h<upMat.length;h++) {
			this.upMat[h] = temp2.upMat[h];
		}
		
		
	}
	
	public Matrix fullMatrix() {
		Matrix full = new Matrix(size,size);
		int zeroesCounter = 0;
		int upMatCounter = 0;
		for (int i=0;i<size;i++) {
			//first print zeroes
			int j=0;
			for(;j<zeroesCounter;j++) {
				full.setElement(0,i,j);
			}
			for(;j<size;j++) {
				full.setElement(upMat[upMatCounter], i, j);
				upMatCounter++;
			}
			zeroesCounter++;
		}
		return full;
	}
	
	public void print1DArray() {
		for (int i=0;i<upMat.length;i++) {
			System.out.print(upMat[i]+"  ");
		}
		System.out.println();
	}
	
	public String toString() {
		Matrix hey = this.fullMatrix();
		String str;
		
		str = hey.toString();
		return str;
	}
	
	public int getDet() {
		Matrix hey = this.fullMatrix();
		int det = 1;
		for (int i=0;i<size;i++) {
			det *= hey.getElement(i, i);
		}
		return det;
	}
	
	public double[] effSolve(double[] b) throws IllegalArgumentException {
		if (b.length != size) {
			throw new IllegalArgumentException("Wrong size for b");
		}
		if (this.getDet()==0) {
			throw new IllegalArgumentException("Zero Determinant");
		}
		
		double[] x = new double[size];
		x[x.length - 1] = b[b.length - 1] / this.upMat[this.upMat.length - 1];
		Matrix me = this.fullMatrix();
		for(int i=size-1-1;i>=0;i--) {
			double sum = 0.000;
			for(int j=size-1;j>i;j--) {
				sum += me.getElement(i, j)*x[j];
			}
			x[i] = (b[i]-sum)/me.getElement(i,i);
		}
		return x;
	}
	
	public static void main(String[] args) {
		int upper[][] = {{5,4,6},{0,2,3},{0,0,7}};
		Matrix upperTest = new Matrix(upper);
		Matrix help;
		
		UpperTriangularMatrix upTest = new UpperTriangularMatrix(upperTest);
		System.out.println(upperTest.toString());
//		
		for(int i=0;i<upTest.upMat.length;i++) {
			System.out.print(upTest.upMat[i]+ "  ");
		}
		
		help = upTest.fullMatrix();
		System.out.println();
		System.out.println(help.toString());
	
		System.out.println("\n"+upTest.getElement(2, 1));
		
		upTest.setElement(868, 0, 0);
		System.out.println(upTest.toString());
		upTest.print1DArray();
	}
	
	

}
