/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package View;

import Controller.Controller;
import Model.Player.Player;
import Model.Tiles.*;
import Model.Tiles.Colors;
import javax.swing.*;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.URL;

/**
 *
 * @author nicktz4
 */
public class GUI extends JFrame implements ActionListener{
	/**
	 * this is the controller of the game
	 */
private Controller game;
	/**
	 * the jPanel
	 */
private JPanel jPanel;	
/**
 * the classLoader
 */
private ClassLoader cldr;  
/**
 * startGame is for the starting menu
 * exit is for the starting menu and inside the game
 * newGame is a button to start a running game again.
 */
private JButton startGame,exit,newGame;
/**
 * this image is for the basicPanel
 */
private Image image;
/**
 * that gets me the photos from the files
 */
private URL imageURL;
/**
 * The field of characters  every player
 */
private JDesktopPane player1Field1;
/**
 * the basicPanel.Includes the board and player's board
 */
private myDesktopPane basicPanel;

/**
 * this button is used  when a player has finished his round 
 */
private JButton endTurnButton;
/**
 * this button is to draw the 4 tiles
 */
private JButton drawButton;

/**
 * these buttons are the Card characters
 */
private JButton[] charList1=new JButton[4];
/**
 * the collection button of tiles of the player
 */
	private JButton currentPlayerCollection,playerCollection2,playerCollection3,playerCollection4;
	/**
	 * the collection button of mosaics on board
	 */
	private JButton mosaicCollection; 
	/**
	 * the collection button of statues on board
	 */
	private JButton statueCollection;
	/**
	 * the collection button of amphorae on board
	 */
	private JButton amphoraeCollection;
	/**
	 * the collection button of skeletons on board
	 */
	private JButton skeletonCollection; 
	/**
	 * the collection button of landSlides on board
	 */
	private JButton landSlideCollection;
/**
 * label for player x turn
 */
private JLabel playerx;
/**
 * label for Use Character
 */
private JLabel useChar;
/**
 * the state of the Currently Player
 */
private JLabel currentPlayerState;
/**
 * Frames for every collection on board
 */
private JFrame mosaicFrame,amphoraFrame,statueFrame,landSlideFrame,skeletonFrame;
/**
 * these variables are used to check if a previous frame is open
 */
private int openMosaic=0,openAmphora=0,openStatue=0,openSkeleton=0,openLandSlide=0;

/**
 * variables to manage the 2nd pick of the player 
 */
private int pMosaic=0,pAmphora=0,pStatue=0,pSkeleton=0;


/**
 *<b>Constructor</b> of GUI.Creates a new Window and initializes some tools. 
 * <b>Postcondition</b> Succesfully creates a new window with some tools.
 * Starts the game from main
 */	
public GUI() {
	game = new Controller();
		player1Field1 = new JDesktopPane();
		
		basicPanel = new myDesktopPane();
		
        	cldr = this.getClass().getClassLoader();  

		
		//den mporeis na alla3eis to megethos toy para8urou.
        	this.setResizable(false);
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        	
		imageURL= cldr.getResource("images_2020/tile_back.png");


        	this.setIconImage(new ImageIcon(imageURL).getImage());
		//this.setLayout(new BorderLayout());
		
		this.setTitle("Amphipolis");

        	this.setPreferredSize(new Dimension(1200, 768));
		
		
		
	
        imageURL= cldr.getResource("images_2020/background.png");

        image=new ImageIcon(imageURL).getImage();

	
		
	JMenu menu = new JMenu("Menu");	

	JMenuItem exitGame = new JMenuItem("Exit");
	exitGame.addActionListener(this);
	menu.add(exitGame);

	JMenuItem newGame = new JMenuItem("New Game");
	newGame.addActionListener(this);
	menu.add(newGame);

	JMenuBar menuBar = new JMenuBar();
	menuBar.add(menu);
	this.setJMenuBar(menuBar);


		currentPlayerState = new JLabel("State: Draw tiles");	
		currentPlayerState.setBounds(950,20,150,50);
		currentPlayerState.setVisible(true);
		basicPanel.add(currentPlayerState,JLayeredPane.DEFAULT_LAYER);
			
		playerx = new JLabel("Player " + game.getCurrentPlayer().getName());
		playerx.setBounds(1030,1,150,50);
		playerx.setVisible(true);

		basicPanel.add(playerx,JLayeredPane.DEFAULT_LAYER);

		useChar = new JLabel("Use character");
		useChar.setBounds(1010,1,500,150);
		useChar.setVisible(true);
		basicPanel.add(useChar,JLayeredPane.DEFAULT_LAYER);
		


		
		player1Field1.setBounds(915, 110, 275, 350);
		basicPanel.add(player1Field1,new JLayeredPane());
        	player1Field1.setBorder(BorderFactory.createMatteBorder(2, 2, 2, 2, Color.yellow));
		player1Field1.setLayout(new GridLayout(2,2));
		
			
		for(int i = 0 ; i < 4 ; i++) {
			charList1[i] = new JButton();
		}
		
		imageURL = cldr.getResource("images_2020/archaeologist.png");
                charList1[0].setIcon(resizeIcon(275/2-10, 350/2-20, new ImageIcon(imageURL)));
		charList1[0].setBackground(Color.GREEN);
		charList1[0].setVisible(true);
		

		imageURL = cldr.getResource("images_2020/assistant.png");
		charList1[1].setIcon(resizeIcon(275/2-10,350/2-20,new ImageIcon(imageURL)));
		charList1[1].setBackground(Color.red);
		charList1[1].setVisible(true);
		
		imageURL = cldr.getResource("images_2020/digger.png");
		charList1[2].setIcon(resizeIcon(275/2-10,350/2-20,new ImageIcon(imageURL)));
		charList1[2].setBackground(Color.BLUE);
		charList1[2].setVisible(true);

		
		imageURL = cldr.getResource("images_2020/professor.png");
		charList1[3].setIcon(resizeIcon(275/2-10,350/2-20,new ImageIcon(imageURL)));
		charList1[3].setBackground(Color.BLACK);
		charList1[3].setVisible(true);
		player1Field1.setVisible(true);
		
		drawButton = new JButton("Draw Tiles");
		drawButton.setBounds(915, 480, 280, 50);
		drawButton.addActionListener(new drawTilesListener());
		basicPanel.add(drawButton,JLayeredPane.DEFAULT_LAYER);
		drawButton.setVisible(true);

		endTurnButton = new JButton("End turn");
		endTurnButton.setBounds(915, 530, 280, 50);
		endTurnButton.addActionListener(new endTurnListener());
		basicPanel.add(endTurnButton,JLayeredPane.DEFAULT_LAYER);
		endTurnButton.setVisible(true);

		currentPlayerCollection = new JButton("CurrentPlayer Collection");
		currentPlayerCollection.setBounds(0, 590, 280,150);
		currentPlayerCollection.addActionListener(new playerCollectionListener());
		basicPanel.add(currentPlayerCollection,JLayeredPane.DEFAULT_LAYER);
		currentPlayerCollection.setVisible(true);

		playerCollection2 = new JButton("Player's p2 collection");
		playerCollection2.setBounds(300,590,300, 100);
		playerCollection2.addActionListener( new playerCollectionListener());
		basicPanel.add(playerCollection2,JLayeredPane.DEFAULT_LAYER);
		playerCollection2.setVisible(true);

		playerCollection3 = new JButton("Player's p3 collection");
		playerCollection3.setBounds(600,590,300, 100);
		playerCollection3.addActionListener( new playerCollectionListener());
		basicPanel.add(playerCollection3,JLayeredPane.DEFAULT_LAYER);
		playerCollection3.setVisible(true);

		playerCollection4 = new JButton("Player's p4 collection");
		playerCollection4.setBounds(900,590,300, 100);
		playerCollection4.addActionListener( new playerCollectionListener());
		basicPanel.add(playerCollection4,JLayeredPane.DEFAULT_LAYER);
		playerCollection4.setVisible(true);
	
		

		
	  mosaicCollection = new JButton("See mosaic Collection"); 
	  mosaicCollection.setBounds(55, 90,210, 50);
	  mosaicCollection.addActionListener(new mosaicListener());
	  basicPanel.add(mosaicCollection,JLayeredPane.DEFAULT_LAYER);
	  statueCollection = new JButton("See statue Collection");
	  statueCollection.setBounds(650,90,210,50);
	  statueCollection.addActionListener  ( new statueListener());
	  basicPanel.add(statueCollection,JLayeredPane.DEFAULT_LAYER);
	 amphoraeCollection = new JButton("See amphorae Collection");
	 amphoraeCollection.setBounds(50 , 430,220,50);
	 amphoraeCollection.addActionListener(new amphoraeListener());
	 basicPanel.add(amphoraeCollection,JLayeredPane.DEFAULT_LAYER);

	 skeletonCollection = new JButton("See skeleton Collection"); 
	 skeletonCollection.setBounds(650,430 ,210, 50);
	 skeletonCollection.addActionListener(new skeletonListener());
	 basicPanel.add(skeletonCollection,JLayeredPane.DEFAULT_LAYER);
	 landSlideCollection = new JButton("See landslide Collection");
	 landSlideCollection.setBounds(350,315, 210,50);
	 landSlideCollection.addActionListener(new landSlideListener());
	 basicPanel.add(landSlideCollection,JLayeredPane.DEFAULT_LAYER);
		    
		
		

GroupLayout layout = new GroupLayout(getContentPane());
	
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(GroupLayout.Alignment.LEADING)
            .addComponent(basicPanel, GroupLayout.PREFERRED_SIZE, 1200, GroupLayout.PREFERRED_SIZE) //1200
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(GroupLayout.Alignment.LEADING)
            .addComponent(basicPanel, GroupLayout.PREFERRED_SIZE, 750, GroupLayout.PREFERRED_SIZE) //585
        );
	 

        pack();
	
		    Graphics g1 = basicPanel.getGraphics();
		    basicPanel.paintComponent(g1);
		    basicPanel.repaint();
		    this.setVisible(true);
		player1Field1.add(charList1[0],JLayeredPane.DEFAULT_LAYER);
		player1Field1.add(charList1[1],JLayeredPane.DEFAULT_LAYER);
		player1Field1.add(charList1[2],JLayeredPane.DEFAULT_LAYER);
		player1Field1.add(charList1[3],JLayeredPane.DEFAULT_LAYER);
		
		
		
		
		this.repaint();
		basicPanel.repaint();
		
		
		

		
}


	@Override
/**
 * this function is used when a setting button has been pushed (newGame,exit)
 */
	public void actionPerformed(ActionEvent e) {
		String buttonString = e.getActionCommand();
		if(buttonString.equals("Exit")) {
			System.exit(0);
		}else if(buttonString.equals(("New Game"))) {
			
			JFrame optionFrame = new JFrame();
			Object[] options = {"Yes","No"};
			 int n;
			n = JOptionPane.showOptionDialog(optionFrame,"Do you really want to play a new game?","New Game",JOptionPane.YES_NO_OPTION,JOptionPane.QUESTION_MESSAGE,null,options,options[0]);
			  if (n==JOptionPane.YES_OPTION){
                            setVisible(false);    
                            new GUI();
                    } else {
				  System.exit(0);
			  }
		}
		else {
			System.out.println("Error");
		}
	}
	/**
	 * A listener to end the program
	 */
	class EndingListener implements ActionListener {

	@Override
	public void actionPerformed(ActionEvent e) {
		System.exit(0);
	}
}
/**
 * a class to paint my basicPanel
 */
class myDesktopPane extends JDesktopPane
{
   private Image backImage = null;
 
   public myDesktopPane()
   {      
      
   }
 
   @Override
   public void paintComponent(Graphics g) {
		super.paintComponent(g);
	int x = (910 - 1430) / 2;
        int y = (585  - 1430) / 2;
		g.drawImage(image,x, y, this);
	}
   
 } 
/**
 * resizes an image with the given values
 * @param width is the new width of the image
 * @param height is the new height of the image
 * @param preImage is the previous image
 * @return the new resized image
 */
private static  Icon resizeIcon(int width,int height ,ImageIcon preImage ) {
	   Image image = preImage.getImage();
	   Image newImage = image.getScaledInstance(width, height, image.SCALE_SMOOTH);
	   return new ImageIcon(newImage);
   }

/**
 * This class is used when a tile button has been pushed
 */
private class tileListener implements ActionListener { 

		@Override
		public void actionPerformed(ActionEvent e) {
			if(game.getPlayerState()==1) {

		String but = (e.getActionCommand());
		
		String value = but.substring(0,1);
		
		but = but.substring(1, but.length());
		int index = Integer.parseInt(value);
		if("Amphora".equals(but)) {
			if(game.getPickTileState()==0) {
		game.getCurrentPlayer().getPlayerCollection().addTile(game.getBoard().getAmphoraeCollection().getTile(index));
		game.getBoard().getAmphoraeCollection().removeTile(game.getBoard().getAmphoraeCollection().getTile(index));
		game.setPickTileState(game.getPickTileState()+1);
		pAmphora = 1;
		if(game.getBoard().getAmphoraeCollection().getSize()==0) {
			game.setPickTileState(2);
		}
			}else
				if(game.getPickTileState()==1) {
					if(pAmphora==1) {
						game.getCurrentPlayer().getPlayerCollection().addTile(game.getBoard().getAmphoraeCollection().getTile(index));
		game.getBoard().getAmphoraeCollection().removeTile(game.getBoard().getAmphoraeCollection().getTile(index));
		game.setPickTileState(game.getPickTileState()+1);
		
					}
				}
		if(game.getPickTileState()==2) {
			game.setPlayerState(2);
			game.getCurrentPlayer().setEndTurn(true);
			currentPlayerState.setText("State: End Turn");
			
			pAmphora = 0;
		}
		amphoraeCollection.doClick();
	
		} else if("Mosaic".equals(but)) {
			
			if(game.getPickTileState()==0) {
				game.getCurrentPlayer().getPlayerCollection().addTile(game.getBoard().getMosaicCollection().getTile(index));
		game.getBoard().getMosaicCollection().removeTile(game.getBoard().getMosaicCollection().getTile(index));
		game.setPickTileState(game.getPickTileState()+1);
		pMosaic = 1;
		if(game.getBoard().getMosaicCollection().getSize()==0) {
			game.setPickTileState(2);
		}
			} else
			if(game.getPickTileState()== 1) {
				if(pMosaic==1) {
						
					
					
			
		game.getCurrentPlayer().getPlayerCollection().addTile(game.getBoard().getMosaicCollection().getTile(index));
		game.getBoard().getMosaicCollection().removeTile(game.getBoard().getMosaicCollection().getTile(index));
		game.setPickTileState(game.getPickTileState()+1);
				}
		} 
		if(game.getPickTileState()==2) {
			game.setPlayerState(2);
			game.getCurrentPlayer().setEndTurn(true);
			currentPlayerState.setText("State: End Turn");
			pMosaic = 0;
		}
		mosaicCollection.doClick();
		} else if("Skeleton".equals(but)) {
			if(game.getPickTileState()==0) {
				game.getCurrentPlayer().getPlayerCollection().addTile(game.getBoard().getSkeletonCollection().getTile(index));
		game.getBoard().getSkeletonCollection().removeTile(game.getBoard().getSkeletonCollection().getTile(index));
		game.setPickTileState(game.getPickTileState()+1);
		pSkeleton = 1;
		
		if(game.getBoard().getSkeletonCollection().getSize()==0) {
			game.setPickTileState(2);
		}
		
			}else
			if(game.getPickTileState()==1) {
				if(pSkeleton == 1) {
				
			
		game.getCurrentPlayer().getPlayerCollection().addTile(game.getBoard().getSkeletonCollection().getTile(index));
		game.getBoard().getSkeletonCollection().removeTile(game.getBoard().getSkeletonCollection().getTile(index));
		game.setPickTileState(game.getPickTileState()+1);
				}
			}
		if(game.getPickTileState()==2) {
			game.setPlayerState(2);
			game.getCurrentPlayer().setEndTurn(true);
			currentPlayerState.setText("State: End Turn");
			pSkeleton = 0;
		}
		skeletonCollection.doClick();
			
		} else if("Statue".equals(but)) {
			if(game.getPickTileState()==0) {
				
			
		game.getCurrentPlayer().getPlayerCollection().addTile(game.getBoard().getStatueCollection().getTile(index));
		game.getBoard().getStatueCollection().removeTile(game.getBoard().getStatueCollection().getTile(index));
		game.setPickTileState(game.getPickTileState()+1);
		pStatue  = 1;
		if(game.getBoard().getStatueCollection().getSize()==0) {
			game.setPickTileState(2);
		}
		}else if(game.getPickTileState()==1) {
			if(pStatue==1) {
				game.getCurrentPlayer().getPlayerCollection().addTile(game.getBoard().getStatueCollection().getTile(index));
		game.getBoard().getStatueCollection().removeTile(game.getBoard().getStatueCollection().getTile(index));
		game.setPickTileState(game.getPickTileState()+1);
			}
		}
		if(game.getPickTileState()==2) {
			game.setPlayerState(2);
			game.getCurrentPlayer().setEndTurn(true);
			currentPlayerState.setText("State: End Turn");
			pStatue = 0;
		}	
		statueCollection.doClick();
		}
			
			}
		

			
			
		}
	}
/**
 * this class is used when the drawTiles Button has been pushed
 */
private class drawTilesListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			if(game.getPlayerState() == 0) {
				
			Player currentPlayer = game.getCurrentPlayer();
			for(int i = 0 ; i < 4;i++) {
			if(game.getBoard().getLandSlideCollection().getSize()!= 16) {	
	 		game.getBoard().addTile(currentPlayer.drawTile(game.getBag()));
			} else {
				JFrame endGame = new JFrame();
    			endGame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
    			endGame.setPreferredSize(new Dimension(600,600));
			endGame.setTitle("GAME ENDED");
			JLabel P1 = new JLabel();
			JLabel P2 = new JLabel();
			JLabel P3 = new JLabel();
			JLabel P4 = new JLabel();
			P1.setBounds(100, 100,300,300);
			P2.setBounds(100, 200,300,300);
			P3.setBounds(100, 300,300,300);
			P4.setBounds(100, 400,300,300);
			int p1Points = game.getPlayer1().calculatePoints() + game.getPlayer1().getStatuePoints(game.calculateStatuePointsForPlayers()) ;
			int p2Points = game.getPlayer2().calculatePoints() + game.getPlayer2().getStatuePoints(game.calculateStatuePointsForPlayers()) ;
			int p3Points =  game.getPlayer3().calculatePoints() + game.getPlayer3().getStatuePoints(game.calculateStatuePointsForPlayers()) ;
			int p4Points = game.getPlayer4().calculatePoints() + game.getPlayer4().getStatuePoints(game.calculateStatuePointsForPlayers() );
			P1.setText("Player 1 points: "+ p1Points);
			P2.setText("Player 2 points: " + p2Points);
			P3.setText("Player 3 points: " + p3Points);
			P4.setText("Player 4 points: " + p4Points);

			int maxPoints = p1Points;
			
			if(maxPoints < p2Points) {
				maxPoints = p2Points;
			}if(maxPoints < p3Points) {
				maxPoints = p3Points;
			}if(maxPoints < p4Points) {
				maxPoints = p4Points;
			}
				JLabel Winner = new JLabel();
				Winner.setBounds(200, 10, 400, 400);
				Winner.setVisible(true);
				endGame.add(Winner);
			if(maxPoints == p2Points) {
				Winner.setText("The BIG WINNER IS PLAYER 2 WITH "+p2Points+" Points!!");
			}else if (maxPoints==p3Points) {
				Winner.setText("The BIG WINNER IS PLAYER 3 WITH "+p3Points+" Points!!");
			}else if(maxPoints == p4Points) {
				Winner.setText("The BIG WINNER IS PLAYER 4 WITH "+p4Points+" Points!!");
			 } else {
				Winner.setText("The BIG WINNER IS PLAYER 1 WITH "+p1Points+" Points!!");
			}
			P1.setVisible(true);
			P2.setVisible(true);
			P3.setVisible(true);
			P4.setVisible(true);
			endGame.add(P1);
			endGame.add(P2);
			endGame.add(P3);
			endGame.add(P4);
			endGame.pack();
			endGame.setVisible(true);
			break;
				
			}
			
			
			}
			game.setPlayerState(1);
			currentPlayerState.setText("Pick tiles from board");
			}
			
		}
	
}
/**
 * this class is used when the nextPlayer button has been pushed
 */
private class endTurnListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			if(game.getCurrentPlayer().getEndTurn()) {
				pAmphora = 0;
				pMosaic=0;
				pSkeleton = 0;
				pStatue=0;
			
				game.setPickTileState(0);
				game.setPlayerState(0);
				game.getCurrentPlayer().setEndTurn(false);
				currentPlayerState.setText("State : Draw Tiles");
			if("p1".equals(game.getCurrentPlayer().getName())) {
				game.setCurrentPlayer(Colors.GREEN);
				playerx.setText("Player "+game.getCurrentPlayer().getName());
				playerCollection2.setText("Player's p1 collection");
				
			}else if("p2".equals(game.getCurrentPlayer().getName())) {
				game.setCurrentPlayer(Colors.BLUE);

				playerCollection3.setText("Player's p2 collection");

				playerx.setText("Player "+game.getCurrentPlayer().getName());
			} else if("p3".equals(game.getCurrentPlayer().getName())) {
				game.setCurrentPlayer(Colors.BROWN);

				playerx.setText("Player "+game.getCurrentPlayer().getName());

				playerCollection4.setText("Player's p3 collection");
			} else {
				game.setCurrentPlayer(Colors.RED);

				playerx.setText("Player "+game.getCurrentPlayer().getName());

				playerCollection4.setText("Player's p4 collection");
				playerCollection3.setText("Player's p3 collection");
				playerCollection2.setText("Player's p2 collection");
			}
		}
		}
	
}
/**
 * this class is used when a character Card button has been pushed
 */
private class characterListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
		}
	
}

/**
 * this class is used when the mosaic Collection button has been pushed
 */
private class mosaicListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			if(openMosaic == 1) {
			mosaicFrame.dispose();
			openMosaic = 0;
			}
			mosaicFrame = new JFrame();
			openMosaic =  1;
    			mosaicFrame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);

    			mosaicFrame.setPreferredSize(new Dimension(600,600));

			mosaicFrame.setTitle("Mosaic Collection on board");
			JPanel panel = new JPanel(new GridLayout(5,5));
			JButton labels[] = new JButton[27];
			for (int i = 0; i < game.getBoard().getMosaicCollection().getSize(); i++) {
			        if(game.getBoard().getMosaicCollection().getSize()!=0) {
			imageURL = cldr.getResource(game.getURL(game.getBoard().getMosaicCollection().getTile(i)));
			labels[i] = new JButton(resizeIcon(275/2-10,350/2-20,new ImageIcon(imageURL)));
			labels[i].addActionListener(new tileListener());
			labels[i].setActionCommand(String.valueOf(i)+"Mosaic");
			
			}		

				panel.add(labels[i]);
    		} 

			mosaicFrame.add(panel);
			mosaicFrame.pack();
		mosaicFrame.setVisible(true);
		}
	
}
/**
 * this class is used when the amphorae Collection button has been pushed
 */
private class amphoraeListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			if(openAmphora == 1) {
			amphoraFrame.dispose();
			openAmphora = 0;
			}
			amphoraFrame = new JFrame();
			openAmphora = 1;
    			amphoraFrame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
    			amphoraFrame.setPreferredSize(new Dimension(600,600));

			amphoraFrame.setTitle("amphorae Collection on board");
			JPanel panel = new JPanel(new GridLayout(5,5));
			JButton labels[] = new JButton[30];
			for (int i = 0; i < game.getBoard().getAmphoraeCollection().getSize(); i++) {
			if(game.getBoard().getAmphoraeCollection().getSize()!=0) {
			imageURL = cldr.getResource(game.getURL(game.getBoard().getAmphoraeCollection().getTile(i)));
			labels[i] = new JButton(resizeIcon(275/2-10,350/2-20,new ImageIcon(imageURL)));
			labels[i].addActionListener(new tileListener());
			labels[i].setActionCommand(String.valueOf(i)+"Amphora");
			}

				panel.add(labels[i]);
        		
    		} 
			amphoraFrame.add(panel);
			amphoraFrame.pack();
		        amphoraFrame.setVisible(true);
		}
	
}
/**
 * this class is used when the skeleton Collection button has been pushed
 */
private class skeletonListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			if(openSkeleton == 1) {
			skeletonFrame.dispose();
			openSkeleton = 0;
			}
			skeletonFrame = new JFrame();
			openSkeleton = 1;
    			skeletonFrame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
    			skeletonFrame.setPreferredSize(new Dimension(600,600));
			skeletonFrame.setTitle("statue Collection on board");
			JPanel panel = new JPanel(new GridLayout(5,5));
			JButton labels[] = new JButton[30];
			for (int i = 0; i < game.getBoard().getSkeletonCollection().getSize(); i++) {
				
			if(game.getBoard().getSkeletonCollection().getSize()!=0) {
			imageURL = cldr.getResource(game.getURL(game.getBoard().getSkeletonCollection().getTile(i)));
			labels[i] = new JButton(resizeIcon(275/2-10,350/2-20,new ImageIcon(imageURL)));
			labels[i].addActionListener(new tileListener());
			labels[i].setActionCommand(String.valueOf(i)+"Skeleton");
			}
				
				panel.add(labels[i]);
			}

        		
    		 
			skeletonFrame.add(panel);
			skeletonFrame.pack();
		        skeletonFrame.setVisible(true);
		}
	
}

/**
 * this class is used when the statue Collection button has been pushed
 */
private class statueListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			if(openStatue == 1) {
			statueFrame.dispose();
			openStatue = 0;
			}
			statueFrame = new JFrame();
			openStatue = 1;
    			statueFrame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
    			statueFrame.setPreferredSize(new Dimension(600,600));
			statueFrame.setTitle("Statue Collection on board");
			JPanel panel = new JPanel(new GridLayout(5,5));
			JButton labels[] = new JButton[24];
			
			for (int i = 0; i < game.getBoard().getStatueCollection().getSize(); i++) {
				if(game.getBoard().getStatueCollection().getSize()!=0) {
			imageURL = cldr.getResource(game.getURL(game.getBoard().getStatueCollection().getTile(i)));
			labels[i] = new JButton(resizeIcon(275/2-10,350/2-20,new ImageIcon(imageURL)));
			labels[i].addActionListener(new tileListener());
			labels[i].setActionCommand(String.valueOf(i)+"Statue");

        		
    		} 

				panel.add(labels[i]);
			}
			statueFrame.add(panel);
			statueFrame.pack();
		        statueFrame.setVisible(true);
		}
	
}

/**
 * this class is used when the landSlide Collection button has been pushed
 */
private class landSlideListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			if(openLandSlide == 1) {
			landSlideFrame.dispose();
			openLandSlide = 0;
			}
			landSlideFrame = new JFrame();
			openLandSlide = 1;
    			landSlideFrame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
    			landSlideFrame.setPreferredSize(new Dimension(600,600));
			landSlideFrame.setTitle("landSlide Collection on board");
			JPanel panel = new JPanel(new GridLayout(5,5));
			JButton labels[] = new JButton[24];
			for (int i = 0; i < game.getBoard().getLandSlideCollection().getSize(); i++) {
				imageURL = cldr.getResource("images_2020/landslide.png");
				labels[i] = new JButton(resizeIcon(275/2-10,350/2-20,new ImageIcon(imageURL)));	
			labels[i].addActionListener(new tileListener());
			labels[i].setActionCommand(String.valueOf(i)+"LandSlide");
				panel.add(labels[i]);

        		
    		} 
			landSlideFrame.add(panel);
			landSlideFrame.pack();
		        landSlideFrame.setVisible(true);
		}
	

}
private class playerCollectionListener implements ActionListener {
	@Override
	public void actionPerformed(ActionEvent e) {
		JFrame frame = new JFrame();
    			frame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
    			frame.setPreferredSize(new Dimension(600,600));
			JPanel panel = new JPanel(new GridLayout(5,5));
				JLabel labels[] = new JLabel[127];
		if("CurrentPlayer Collection".equals(e.getActionCommand())) {
			
			
			frame.setTitle("Current Player Collection");
			for(int i = 0 ; i < game.getCurrentPlayer().getPlayerCollection().getSize();i++) {
				
				imageURL = cldr.getResource(game.getURL(game.getCurrentPlayer().getPlayerCollection().getTile(i)));
				labels[i] = new JLabel(resizeIcon(275/2-10,350/2-20,new ImageIcon(imageURL)));
				panel.add(labels[i]);
			}
			
		}else if("Player's p2 collection".equals(e.getActionCommand())) {
			
				
				frame.setTitle("Player's 2 Collection");
			for(int i = 0 ; i < game.getPlayer2().getPlayerCollection().getSize();i++) {
				imageURL = cldr.getResource(game.getURL(game.getPlayer2().getPlayerCollection().getTile(i)));
				labels[i] = new JLabel(resizeIcon(275/2-10,350/2-20,new ImageIcon(imageURL)));
				panel.add(labels[i]);
			}
		} else if("Player's p3 collection".equals(e.getActionCommand())) {
			
				
				frame.setTitle("Player's 3 Collection");
			for(int i = 0 ; i < game.getPlayer3().getPlayerCollection().getSize();i++) {
				imageURL = cldr.getResource(game.getURL(game.getPlayer3().getPlayerCollection().getTile(i)));
				labels[i] = new JLabel(resizeIcon(275/2-10,350/2-20,new ImageIcon(imageURL)));
				panel.add(labels[i]);
			}
		} else if("Player's p4 collection".equals(e.getActionCommand())) {
			
				
				frame.setTitle("Player's 4 Collection");
			for(int i = 0 ; i < game.getPlayer4().getPlayerCollection().getSize();i++) {
				imageURL = cldr.getResource(game.getURL(game.getPlayer4().getPlayerCollection().getTile(i)));
				labels[i] = new JLabel(resizeIcon(275/2-10,350/2-20,new ImageIcon(imageURL)));
				panel.add(labels[i]);
			}
		}else {
				
				frame.setTitle("Player's 1 Collection");
			for(int i = 0 ; i < game.getPlayer1().getPlayerCollection().getSize();i++) {
				imageURL = cldr.getResource(game.getURL(game.getPlayer1().getPlayerCollection().getTile(i)));
				labels[i] = new JLabel(resizeIcon(275/2-10,350/2-20,new ImageIcon(imageURL)));
				panel.add(labels[i]);
			}
		}
		frame.add(panel);
		frame.pack();
		frame.setVisible(true);
	}
}
}
