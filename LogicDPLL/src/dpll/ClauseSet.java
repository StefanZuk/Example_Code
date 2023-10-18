package dpll;

import java.util.ArrayList;

public class ClauseSet {
	private ArrayList<Clause> clauses;
	
	public ArrayList<Clause> getClauses() {
		return clauses;
	}
	
	public int getSize() {
		return clauses.size();
	}
	
	public ClauseSet(Clause... clauses) {
		this.clauses = new ArrayList<Clause>();
		for(Clause clause : clauses) {
			this.clauses.add(clause);
		}
	}
	
	public ClauseSet copy() {
		ClauseSet clauseSet = new ClauseSet();
		for(int i = 0; i < clauses.size(); i++) {
			Clause clause = new Clause();
			for(int j = 0; j < clauses.get(i).getSize(); j++) {
				Literal lit = clauses.get(i).getLiterals().get(j);
				clause.addLiteral(new Literal(lit));
			}
			clauseSet.addClause(clause);
		}
		
		return clauseSet;
	}
	
	public void addClause(Clause clause) {
		clauses.add(clause);
	}
	
	public ClauseSet addUnitClause(Literal lit) {
		Clause clauseToAdd = new Clause();
		clauseToAdd.addLiteral(lit);
		this.clauses.add(clauseToAdd);
		
		return this;
	}
	
	public void deleteClause(Literal lit) {
		int index = this.clauseContainsLit(lit);
		while(index >= 0) {
			this.clauses.remove(index);
			index = this.clauseContainsLit(lit);
		}
	}
	
	public int clauseContainsLit(Literal lit) {
		for(int i = 0; i < this.clauses.size(); i++) {
			if(this.clauses.get(i).containsLiteral(lit))
				return i;
		}
		
		return -1;
	}
	
	public Literal deleteUnitClause() {
		Literal unitClauseLit = null;
		for(int i = 0; i < this.clauses.size(); i++) {
			if(this.clauses.get(i).isUnitClause()) {
				unitClauseLit = new Literal(this.clauses.get(i).getUnitClauseLit());
				this.clauses.remove(i);
			}
		}	
		return unitClauseLit;
	}
	
	public boolean containsUnitClause() {
		for(int i = 0; i < this.clauses.size(); i++) {
			if(this.clauses.get(i).isUnitClause())
				return true;
		}
		return false;
	}
	
	public boolean isEmptySet() {
		return (this.clauses.size() == 0) ? true : false;
	}
	
	public boolean containsEmptyClause() {
		for(int i = 0; i < this.clauses.size(); i++) {
			if(this.clauses.get(i).isEmptyClause())
				return true;
		}	
		return false;
	}
	
	public void printClauseSet() {
		if(getSize() == 0) {
			System.out.println("{}");
			return;
		}
		
		String clauseSetString = "{" + this.clauses.get(0).printClause();
		for(int i = 1; i<this.clauses.size(); i++) {
			clauseSetString += "," + this.clauses.get(i).printClause();
		}
		clauseSetString += "}";
		
		System.out.println(clauseSetString);
	}
	
	public Clause allLiterals() {
		Clause retClause = new Clause();
		Clause tempClause = new Clause();
		for(int i = 0; i<this.clauses.size(); i++) {
			tempClause = this.clauses.get(i);
			for(int j = 0; j<tempClause.getSize(); j++) {
				Literal tmpLiteral = tempClause.getLiterals().get(j);
				if(!retClause.containsLiteral(tmpLiteral)) {
					/*if(tmpLiteral.isNegate())
						retClause.addLiteral(new Literal(1,tmpLiteral));
					else
						retClause.addLiteral(tmpLiteral);*/
					
					retClause.addLiteral(tmpLiteral);
				}
			}
		}
		return retClause;
	}
	
	public Literal countMaxOccLiteral(Clause allVarsP) {
		Clause allVars = allVarsP.copy();
		int counter = 0;
		int max = 0;
		Literal winnerLiteral = null;
		while(!allVars.isEmptyClause()) {
			Literal checkLiteral = allVars.getLiterals().get(0);
			for(int i=0; i<this.getSize(); i++) {
				for(int j=0; j<this.getClauses().get(i).getSize(); j++) {
					if(this.getClauses().get(i).getLiterals().get(j).getVar() == checkLiteral.getVar() &&
							this.getClauses().get(i).getLiterals().get(j).isNegate() == checkLiteral.isNegate()) {
						counter++;
					}
				}
				if(counter > max) {
					winnerLiteral = allVars.getLiterals().get(0);
					max = counter;
					
				}		
			}
			counter=0;
			allVars.removeFirstLiteral();
		}		
		return winnerLiteral;	
	}
	
	public Clause calcRecOrder() {
		Clause allVars = this.allLiterals();
		Clause orderClause = new Clause();
		Clause returnClause = new Clause();
		
		while(!allVars.isEmptyClause()) {
			Literal currentWinnerLit = countMaxOccLiteral(allVars);
			allVars.removeFromClause(currentWinnerLit);
			orderClause.addLiteral(currentWinnerLit);
		}
	
		for(int i=0;  i<orderClause.getSize(); i++) {
			if(returnClause.containsLiteral(new Literal(1,orderClause.getLiterals().get(i))))
				continue;
			else 
				returnClause.addLiteral(orderClause.getLiterals().get(i));			
		}

		return returnClause;
	}
}










