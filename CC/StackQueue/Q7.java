public class Animal{
	private int type;
	
	public Animal(){
		type = 0;
	}

	public Animal(int i){
		type = i;
	}
	public  setAnimal(int i){
		type = i;
	}
	public int getAnimal(){
		return type;
	}
}


class shelter{
	private LinkedList<Animal> list;	
	private Stack<Animal> side;
	public shelter(){
		list = new LinkedList<animal>(); 
		side = new Stack<animal>(); 
	}

	public void insert(Animal a) throws Exception{
		if(!list.add(a)) throw new Exception("insert failure!");		
	}

	public int length(){
		return list.length();
	}

	public boolean isEmpty(){
		return list.isEmpty();
	}

	public Animal element(){
		return list.element();
	}

	public Animal removeWithNoType(){
		return list.remove();
	}

	public Animal removeDog(){
		Animal dog;
		while(!list.isEmpty()){
			if(list.element().getAnimal() == 1){
				dog = list.remove();
				while(!side.isEmpty()) list.addFirst(side.pop());
				return dog;
			}else{
				side.push(list.remove);
			}
		}
		while(!side.isEmpty()) list.addFirst(side.pop());
		return dog;
	}

    public Animal removeCat(){
        Animal cat;
        while(!list.isEmpty()){
            if(list.element().getAnimal() == 1){
                cat  = list.remove();
                while(!side.isEmpty()) list.addFirst(side.pop());
                return cat;
            }else{
                side.push(list.remove);
            }
        }
        while(!side.isEmpty()) list.addFirst(side.pop());
        return cat;
    }
}
