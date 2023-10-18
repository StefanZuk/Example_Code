package dpll;

public class DpllSolver {	
	
	public Clause solutionSet = new Clause();
	
	public static void main(String[] args) {
		Literal nx = new Literal('x', true, -1);
		Literal x = new Literal('x', false, -1);
		
		Literal ny = new Literal('y', true, -1);
		Literal y = new Literal('y', false, -1);
		
		Literal nz = new Literal('z', true, -1);
		Literal z = new Literal('z', false, -1);
		
		Literal na = new Literal('a', true, -1);
		Literal a = new Literal('a', false, -1);
		
		Literal nb = new Literal('b', true, -1);
		Literal b = new Literal('b', false, -1);
		
		Literal nw = new Literal('w', true, -1);
		Literal w = new Literal('w', false, -1);
		
		Clause c1 = new Clause(nx, ny ,nz);
		Clause c2 = new Clause(nx, ny, z, nw, na);
		Clause c3 = new Clause(nx, ny, z, w, nb);
		Clause c4 = new Clause(nx, ny, z, w, b);
		Clause c5 = new Clause(nx, y);
		Clause c6 = new Clause(nx, ny, z, nw, a);
		Clause c7 = new Clause(x, ny, nz);
		Clause c8 = new Clause(x, ny, z, a);
		Clause c9 = new Clause(x, y, nb);
		
		ClauseSet s = new ClauseSet(c1,c2,c3,c4,c5,c6,c7,c8,c9);
		
		Clause literals = s.calcRecOrder();
		
		System.out.print("inital clauseset: ");
		s.printClauseSet();
		System.out.println("Literal order: " + literals.printClause());
		
		DpllSolver dpllSolver = new DpllSolver();
		
		if(dpllSolver.dpllSolve(s, literals)) {
			System.out.print("Lösbar mit: ");
			System.out.println("Solution set: " + dpllSolver.solutionSet.printClause());
		}
		else
			System.err.println("Unlösbar!");
	}
	
	
	
	public boolean dpllSolve(ClauseSet s, Clause literals) {

		System.out.print("Set pre trivial cases: ");
		s.printClauseSet();
		
		int unitClauseCounter = 0;
		

		Literal unitClauseLit = null;
		Literal nunitClauseLit = null;
		while(s.containsUnitClause()) {
			unitClauseCounter++;
			unitClauseLit = new Literal(s.deleteUnitClause());

			solutionSet.addLiteral(unitClauseLit);
			
			nunitClauseLit = new Literal(1 ,unitClauseLit);
			s.deleteClause(unitClauseLit);
			for(int i = 0; i<s.getSize(); i++) {
				s.getClauses().get(i).removeFromClause(nunitClauseLit);
			}
			
		}
		
		System.out.print("Set after trivial cases: ");
		s.printClauseSet();
		
		if(s.containsEmptyClause()) {
			for(int i = 0; i < unitClauseCounter; i++)
				this.solutionSet.removeLastLiteral();
			return false;
		}
			
		else if(s.isEmptySet())
			return true;
		else {
			if(literals.getSize() == 0) {
				for(int i = 0; i < unitClauseCounter; i++)
					this.solutionSet.removeLastLiteral();
				return false;
			}
			
			Literal litToAdd = literals.getLiterals().get(0);
			Literal nlitToAdd = new Literal(1,litToAdd);
			literals.removeFirstLiteral();
			
			ClauseSet tmpSet = s.copy();
			Clause tmpLiterals = literals.copy();
			System.out.println("--------------------------Try: " + litToAdd.printLiteral());
			if(dpllSolve(s.addUnitClause(litToAdd), literals))
				return true;
			s = tmpSet.copy();
			literals = tmpLiterals.copy();
			
			System.out.println("--------------------------Try: " + nlitToAdd.printLiteral());
			if(dpllSolve(s.addUnitClause(nlitToAdd), literals))
				return true;
			else {
				for(int i = 0; i < unitClauseCounter; i++)
					this.solutionSet.removeLastLiteral();
				unitClauseCounter = 0;
				return false;
			}
		}
	}
}
