package dpll;

import java.util.ArrayList;

public class Clause {
	private ArrayList<Literal> literals;
	
	//Constructor empty clause
	public Clause() {
		this.literals = new ArrayList<Literal>(0);
	}
	
	//Constructor clause 
	public Clause(Literal... literals) {
		this.literals = new ArrayList<Literal>();
		for(Literal literal : literals) {
			this.literals.add(literal);
		}
	}
	
	//Add literal to clause
	public void addLiteral(Literal lit) {
		this.literals.add(lit);
	}
	
	public int getSize() {
		return this.literals.size();
	}
	
	//get list of literals of clause
	public ArrayList<Literal> getLiterals() {
		return literals;
	}
	
	//Return copy of clause
	public Clause copy() {
		Clause clause = new Clause();
		for(int j = 0; j < this.literals.size(); j++) {
			Literal lit = this.literals.get(j);
			clause.addLiteral(new Literal(lit));
		}
		return clause;
	}
	
	//check if clause is unit-clause
	public boolean isUnitClause() {
		return (this.literals.size() == 1) ? true : false;
	}
	
	//check if clause is empty
	public boolean isEmptyClause() {
		return (this.literals.size() == 0) ? true : false;
	}
	
	//Return Literal of unit-clause
	public Literal getUnitClauseLit() {
		return this.literals.get(0);
	}
	
	//Check if clause contains literal
	public boolean containsLiteral(Literal lit) {
		for(int i = 0; i < this.literals.size(); i++) {
			if((this.literals.get(i).getVar() == lit.getVar()) && (this.literals.get(i).isNegate() == lit.isNegate()))
				return true;
		}
		return false;
	}
	
	//Remove literal from clause
	public void removeFromClause(Literal lit) {
		while(this.containsLiteral(lit)) {
			for(int i = 0; i < this.literals.size(); i++) {
				if((this.literals.get(i).getVar() == lit.getVar()) && (this.literals.get(i).isNegate() == lit.isNegate())) {
					this.literals.remove(i);
					break;
				}
			}
		}
	}
	
	//Remove first literal of clause
	public void removeFirstLiteral() {
		this.literals.remove(0);
	}
	
	//Remove last literal of clause
	public void removeLastLiteral() {
		this.literals.remove(this.literals.size()-1);
	}
	
	//Return clause as String
	public String printClause() {
		if(isEmptyClause())
			return "{}";
		
		String clauseString = "{" + this.literals.get(0).printLiteral();
		for(int i = 1; i<this.literals.size(); i++) {
			clauseString += "," + this.literals.get(i).printLiteral();
		}
		clauseString += "}";
		return clauseString;
		
	}
	
}
