package dpll;

public class Literal {
	private char var;
	private boolean negate;
	private int value; //(-1 = false, 1 = true)
	
	//Constructor new literal
	public Literal(char var, boolean negate, int value) {
		this.var = var;
		this.negate = negate;
		this.value = value;
	}
	
	//Constructor copy literal
	public Literal(Literal lit) {
		this.var = lit.getVar();
		this.negate = lit.isNegate();
		this.value = lit.getValue();
	}
	
	//Constructor negate literal
	public Literal(int second, Literal lit) {
		this.var = lit.getVar();
		this.negate = !lit.isNegate();
		this.value = lit.getValue();
	}
	
	public char getVar() {
		return var;
	}

	public boolean isNegate() {
		return negate;
	}
		
	public void setValue(int value) {
		this.value = value;
	}
	
	public int getValue() {
		return (negate) ? value*-1 : value;
	}
	
	//Return literals as string
	public String printLiteral() {
		String literalString = "";
		if(this.negate) 
			literalString += "-" + var;
		else 
			literalString += var;
		
		return literalString;
	}
	
	//Compare literal with another literal
	public boolean compareLiterals(Literal compareLit) {
		if(this.getVar() == compareLit.getVar() && this.isNegate() == compareLit.isNegate())
			return true;
		return false;
	}
	
	//Compare if literal l1 is same variable as literal l2
	public boolean compareVar(Literal compareLit) {
		if(this.getVar() == compareLit.getVar())
			return true;
		return false;
	}
	
}
