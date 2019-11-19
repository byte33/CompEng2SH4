
public class SLLSet {
	
	private int size;
	private SLLNode firstNode;
	
//	Constructors start here
	public SLLSet() { //create an empty set
		size = 0;
		firstNode = null;
	}
	
	public SLLSet(int[] sortedArray) {
		if (sortedArray.length==0) {size=0;firstNode=null;return;}//empty set
		SLLNode temp = new SLLNode(sortedArray[0],null); //create the zeroth node
		firstNode = temp;
		
		for (int i=1;i<sortedArray.length;i++) { //jump through the rest of the array elements, creating new nodes
			temp.next = new SLLNode(sortedArray[i],null);
			temp = temp.next;	
		}
		size = sortedArray.length;  //set size
		
	}
	
//	Methods start here
	public int getSize() {
		
		return size;
	}
	
	public SLLSet copy() {
		SLLSet copied = new SLLSet();  //create new SLLSet object
		copied.size = this.size;  //equate sizes
		SLLNode temp = this.firstNode;
		SLLNode tempNew = new SLLNode(temp.value,null);
		
		copied.firstNode = tempNew;
		for (int i=1;i<copied.size;i++) {
			temp = temp.next;
			tempNew.next = new SLLNode(temp.value,null);  //create new objects with the same value
			tempNew = tempNew.next;
		}
		return copied; //new linked list
	}
//	
	public boolean isIn(int val) {
		SLLNode temp = firstNode;
		while(temp.next != null) { //run through the entire linked list and check if the value is the same as the input value
			if (val == temp.value) {
				return true;
			}
			temp = temp.next;
		}
		if (temp.value == val) {
			return true; //check the very last index
		} else {
		return false;
		}
	}
//	
	public void add(int val) {
		if (size==0) { //if the list is empty, create the first node
			SLLNode temp = new SLLNode(val,null);
			size++;
			firstNode = temp;
			return;
		}
		SLLNode temp = firstNode;
		
		if (temp.value == val) {return;} //if the value is the value of the first node, return right away 
		
		if (temp.value > val) { //this runs when the val is smaller than the first node, meaning that firstNode is now a new node
			temp = new SLLNode(val,temp);
			firstNode = temp;
			size++;
			return;
		}
		
		while(temp.next != null) {
			if (temp.value == val) {return;} //if it finds that the value already exists, exit the function
			else if (val < temp.next.value) { //check ahead
				temp.next = new SLLNode(val,temp.next);
				size++;
				return;
			}
			temp = temp.next;
		}
		if (temp.value == val) {return;} //check the last case
		temp.next = new SLLNode(val,null);
		size++;
	}
//	
	public void remove(int val) {
		SLLNode temp = firstNode;
		SLLNode lagTemp = firstNode;
		if (temp==null) {return;} //check if the list is empty
		int i = 0; //counter
		if (temp.value == val) {  //if the value is the first node, point firstnode to the next index
			firstNode = temp.next;
			size--;
			return;
		}
		while(temp.next != null) {
			if (temp.value == val) {
				lagTemp.next = temp.next;
				size--;
				return;
			}
			if (i>0) {lagTemp = temp;}
			temp = temp.next;
			i++;
		}
		if (temp.value == val) {
			lagTemp.next = temp.next;
			size--;
		}
	}
//	
	public SLLSet union(SLLSet set) {
		if (this.firstNode == null) {
			SLLSet unionedSet = set.copy();
			return unionedSet;
		}
		if (set.firstNode == null) {
			SLLSet unionedSet = this.copy();
			return unionedSet;
		}
		
		
		SLLSet unionedSet = set.copy();

		SLLNode temp = this.firstNode;
		SLLNode temp2 = set.firstNode;
		
		for (int i=0;i<this.size;i++) {
			unionedSet.add(temp.value);
			temp = temp.next;
		}
		
		return unionedSet;
	}
//	
	public SLLSet intersection(SLLSet set) {
		SLLSet intersectedSet = new SLLSet();
		if (this.firstNode == null || set.firstNode == null) {return intersectedSet;}
		SLLNode temp = this.firstNode;
		for(int i=0;i<this.size;i++) {
			if(set.isIn(temp.value)) {
				intersectedSet.add(temp.value);
			}
			temp = temp.next;
		} 
		

		
		return intersectedSet;
	}
//	
	public SLLSet difference(SLLSet set) {
		SLLSet differenceSet = new SLLSet();
		if (this.firstNode == null) {return differenceSet;}
		if (set.firstNode == null) {differenceSet = this.copy();return differenceSet;}
		SLLNode temp = this.firstNode;
		SLLNode temp2 = set.firstNode;
		if (this.size>=set.getSize()) {
			for(int i=0;i<this.size;i++) {
				if(!set.isIn(temp.value)) {
					differenceSet.add(temp.value);
				}
				temp = temp.next;
			}
		} else {
			for(int i=0;i<set.size;i++) {
				if(!this.isIn(temp2.value)) {
					differenceSet.add(temp2.value);
				}
				temp2 = temp2.next;
			}
		} 
		

		
		return differenceSet;
		
	}
//	
	public static SLLSet union(SLLSet[] sArray) {
		SLLSet staticUnionSet = sArray[0];
		for (int i=1;i<sArray.length;i++) {
			staticUnionSet = staticUnionSet.union(sArray[i]);
		}
		return staticUnionSet;
	}
//	
	public String toString() {
		String hi = new String("");
		SLLNode lastNode = firstNode;
		if (lastNode == null) {return hi;}
		while(lastNode.next != null) {
			hi += lastNode.value;
			hi += " ";
			lastNode = lastNode.next;
		}
		hi += lastNode.value;
		return hi;
	}
	
//	public static void main(String[] args) {
//		int[] arr = {0,1,2,4,6,7,8,9,13,33,34,45};
//		int[] arr2 = {1,2,13,23,24,26,27,33,34,45};
//        int arr3[]  = {0,1,2,3,4};
//        int arr4[]  = {0,1};
//		SLLSet testSet = new SLLSet(arr);
//		SLLSet testSet2 = new SLLSet(arr2);
//		SLLSet testSet3 = new SLLSet(arr3);
//		SLLSet testSet4 = new SLLSet(arr4);
//		SLLSet newSet;
//		SLLSet unionSet;
//		SLLSet intersectSet;
////		System.out.println(testSet.firstNode.value);
////		System.out.println(testSet.getSize());
////		System.out.println(testSet.isIn(1));
////		testSet.add(3);
////		testSet.remove(3);
//		System.out.println();
//		System.out.println(testSet3.toString());
////		newSet = testSet.copy();
//		System.out.println(testSet4.toString());
////		unionSet = testSet.union(testSet2);
////		System.out.println(unionSet.toString());
////		intersectSet = testSet.intersection(testSet2);
////		System.out.println(intersectSet.toString());
//		unionSet = testSet3.union(testSet4);
//		System.out.println(unionSet.toString());
//		
//		
//	}
}
