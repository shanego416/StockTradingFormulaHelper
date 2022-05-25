//
//  main.c
//  TradingFormulaHelper
//
//  Created by Shane
//

#include <stdio.h>

int main()
{
    float profit, avg = 0.0, sellPrice = 0.0, shares = 0.0;
    float profitPercentage = 0.0;
    float lossPercentage;
    float lossPrice, stopLossPrice;
    float profitVar;
    float percentage, percentagePoint, number;
    float shareNum, price, newAvg, shares1, shares2, totalShares, total;
    int menuSelection = 0;
    int yesOrNo = 0;
    char a;
    
    do {
        
        printf("\n");
        printf("\n                  Trading Calculater              \n");
        printf("           ------------------------------\n\n");
        printf("                        MENU                       \n");
        printf("|--------------------------------------------------|\n");
        printf("|    1. Calculate Profit                           |\n");
        printf("|    2. Calculate Profit Percentage                |\n");
        printf("|    3. Calculate Loss Percentage                  |\n");
        printf("|    4. Calculate Stop Loss Sell Point             |\n");
        printf("|    5. Calculate Profit Sell Point / Limit Sell   |\n");
        printf("|    6. Calculate Average Price After New Purchase |\n");
        printf("|    7. Calculate a Percentage of a Number         |\n");
        printf("|    0. Quit                                       |\n");
        printf("|--------------------------------------------------|\n");
        printf("\nEnter a number from the menu to make a selction: >");
        scanf("%d", &menuSelection);
    
    
        switch (menuSelection)
        {
            case 1:
                printf("\nCalculate Profit\n");
                printf("\nEnter average price: >$");
                scanf("%f", &avg);
                printf("\n\nEnter sell price: >$");
                scanf("%f", &sellPrice);
                printf("\nEnter the number of shares in this trade: >");
                scanf("%f", &shares);
                
                profit = sellPrice - avg;
                profit = profit * shares;
                
                printf("\n\n----->Your profit on this trade is $%.2f<-----\n", profit);
                printf("\nAnother calculation? 1 for YES and 2 for No: >");
                scanf(" %d", &yesOrNo);
                break;
        
            case 2:
                printf("\nCalculate Profit Percentage\n");
                printf("\nEnter average price per share: >$");
                scanf("%f", &avg);
                printf("\n\nEnter sell price per share: >$");
                scanf(" %f", &sellPrice);
                
                profit = sellPrice - avg;
                profitPercentage = 100 * profit / avg;
                
                printf("\n---->You made %.0f%% on this trade.<-----\n", profitPercentage);
                printf("\nAnother calculation? 1 for YES and 2 for No: >");
                scanf(" %d", &yesOrNo);
                break;
            
            case 3:
                printf("\nCalculate Loss Percentage\n");
                printf("\nEnter average price per share: >$");
                scanf(" %f", &avg);
                printf("\n\nEnter the average SELL price per share: >$");
                scanf(" %f", &sellPrice);
                
                profit = sellPrice - avg;
                lossPercentage = 100 * profit / avg;
                //lossPercentage = lossPercentage * -1;
                if (lossPercentage < 0) {
                    printf("\n\n----->You lost %.2f%% on this trade.<-----\n", lossPercentage);
                } else {
                    printf("\n\n----->You made %.2f%% on this trade.<-----\n", lossPercentage);
                }
                printf("\nAnother calculation? 1 for YES and 2 for No: >");
                scanf(" %d", &yesOrNo);
                break;
                
        
            case 4:
                printf("\nCalculate Stop Loss Price\n");
                printf("\nEnter average price per share: >$");
                scanf(" %f", &avg);
                printf("\n\nEnter the percent you're willing to lose: >");
                scanf(" %f", &lossPercentage);
                
                lossPercentage = lossPercentage / 100;
                lossPrice = avg * lossPercentage;
                lossPercentage = lossPercentage * 100;  
                stopLossPrice = avg - lossPrice;
                
                printf("\n\n---->To stop your losses at %.2f%%, set your stoploss price at $%.2f<-----\n", lossPercentage, stopLossPrice);
                printf("\nAnother calculation? 1 for YES and 2 for No: >");
                scanf(" %d", &yesOrNo);
                break;
            
            case 5:
                printf("\nCalculate Profit Sell Price / Limit Sell Price\n");
                printf("\nEnter average price per share: >$");
                scanf(" %f", &avg);
                printf("\n\nEnter the percentage you would like to make: >");
                scanf(" %f", &profitPercentage);
                
                profitVar = profitPercentage / 100 + 1;
                sellPrice = profitVar * avg;
                
                printf("\n\n----->In order to make %.2f%% on this trade, sell shares at $%.2f<-----\n", profitPercentage, sellPrice);
                printf("\nAnother calculation? 1 for YES and 2 for No: >");
                scanf(" %d", &yesOrNo);
                break;
            
            case 6:
                printf("\nCalculate New Average Price After New Purchase.\n");
                printf("\nEnter you current avg price: >$");
                scanf(" %f", &avg);
                printf("\nEnter the amount of shares owned: >");
                scanf(" %f", &shareNum);
                printf("\nEnter price per share of new purchase: >$");
                scanf(" %f", &price);
                printf("\nEnter the amount of shares in new purchase: >");
                scanf(" %f", &shares);
                
                shares1 = avg * shareNum;
                shares2 = price * shares;
                totalShares = shareNum + shares;
                total = shares1 + shares2;
                newAvg = total / totalShares;
                
                printf("\nAfter this purchase your new average price would be %.2f", newAvg);
                printf("\nAnother calculation? 1 for YES and 2 for No: >");
                scanf(" %d", &yesOrNo);
                
                break;
                
                
            case 7:
                printf("\nCalculate a Percentage of a Number\n");
                printf("\nEnter a number: >");
                scanf(" %f", &number);
                printf("\n\nEnter the percentage of that number you would like to find: >%%");
                scanf(" %f", &percentage);
                
                percentagePoint = percentage / 100 * number;
                
                printf("\n\n----->%.2f%% of %.2f is %.2f<-----\n", percentage, number, percentagePoint);
                printf("\nAnother calculation? 1 for YES and 2 for No: >");
                scanf(" %d", &yesOrNo);
                
                break;
            
            default:
                printf("Invalid input");
                break;
        }
        scanf(" %c", &a);
    } while (menuSelection != 0  && yesOrNo != 2 && a == a);
    
    return 0;
}

