package sierpinski;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;

@SuppressWarnings("serial")
public class Sierpinski extends Canvas {
	static final int imageSize = 800;
	static final int defaultOrder = 7;
	
	public class TwoDpoint {
		public int x;
		public int y;
		
		public TwoDpoint(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	
    public static void main(String[] args) {
        JFrame frame = new JFrame("My Drawing");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Canvas canvas = new Sierpinski();
        canvas.setSize(imageSize, imageSize);
        frame.add(canvas);
        frame.pack();
        frame.setVisible(true);
    }

    public void paint(Graphics g) {
        g.drawRect(0, 0, imageSize, imageSize);;
        TwoDpoint leftBot = new TwoDpoint(0, imageSize);
        TwoDpoint rightBot = new TwoDpoint(imageSize, imageSize);
        TwoDpoint tip = new TwoDpoint(imageSize/2, 0);
        drawTri(leftBot, rightBot, tip, Color.BLACK, g);
        drawSierpinski(leftBot, rightBot, tip, defaultOrder, g, imageSize/4, Color.BLACK);
      
    }
    
    public void drawSierpinski(TwoDpoint leftBot, TwoDpoint rightBot , TwoDpoint tip, int order, Graphics g, int offset, Color c) {
    	if(order >= 0) {
    		
    		//draw the flipped triangle into the given coordinates
    		drawTri(new TwoDpoint(leftBot.x+offset, tip.y+(2*offset)), 
    				new TwoDpoint(rightBot.x-offset, rightBot.y-(2*offset)), 
    				new TwoDpoint(leftBot.x+(2*offset), leftBot.y), 
    				c, g);

    		//recursively go to the left sub-triangle
    		drawSierpinski(new TwoDpoint(leftBot.x, leftBot.y), 
    				new TwoDpoint(leftBot.x + (2*offset), rightBot.y), 
    				new TwoDpoint(leftBot.x+offset, tip.y+(2*offset)), 
    				order-1, g, offset/2, Color.BLUE);
    		
    		//recursively go to the right sub-triangle
    		drawSierpinski(new TwoDpoint(tip.x, leftBot.y), 
    				new TwoDpoint(rightBot.x, rightBot.y), 
    				new TwoDpoint(tip.x+offset, tip.y+(2*offset)), 
    				order-1, g, offset/2, Color.GREEN);
    		
    		//recursively go to the top sub-triangle
    		drawSierpinski(new TwoDpoint(leftBot.x+offset, tip.y+(2*offset)), 
    				new TwoDpoint(tip.x+offset, tip.y+(2*offset)), 
    				new TwoDpoint(tip.x, tip.y), 
    				order-1, g, offset/2, Color.RED);
    	} 

    }
    
    public static void drawTri(TwoDpoint l, TwoDpoint r, TwoDpoint t, Color c, Graphics g) {
    	g.setColor(c);
    	//printvec(l, "l", c);
    	//printvec(r, "r",c );
    	//printvec(t, "t",c);
    	//System.out.println();
    	g.drawLine(l.x, l.y, r.x, r.y);
    	g.drawLine(r.x, r.y, t.x, t.y);
    	g.drawLine(t.x, t.y, l.x, l.y);
    }
    
    public static void printvec(TwoDpoint l, String name, Color c) {
    	System.out.println("point: " + name);
    	System.out.println("(x,y): " + l.x + ","+ l.y + " color: " + c);
 
    }
}