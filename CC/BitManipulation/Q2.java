public String printBinary(double num){
	if(num < 0 || num > 1) return "ERROR";

	StringBuilder result = new StringBuilder();
	result.append("0.");
	while(num > 0){
		if(result.length() > 32){
			return "ERROR";
		}
		double temp = num * 2;
		if(temp > 1){
			result.append("1");
			num = num - 1;
		}else{
			result.append("0");
			num = temp;
		}	
	}
	return result.toString();
}
