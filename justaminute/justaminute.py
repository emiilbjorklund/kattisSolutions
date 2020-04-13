def avg(mSec,dSec):
    # Check the difference
    return sum(mSec)/sum(dSec)

if __name__ == "__main__":
    while True:
        dSec = []
        mSec = []
        try:
            ob = int(input("")) 
            if ob < 1 or ob > 1000:
                raise ValueError      
        except ValueError:
            continue
        try:
            for i in range(ob):
                userinput = input("").split()
                if (int(userinput[0]) > 0 or int(userinput[0]) < 60) or (int(userinput[1]) > 0 or int(userinput[1]) < 3600):
                    # Converting to sec
                    dSec.append(int(userinput[0]) * 60)
                    mSec.append(int(userinput[1]))
                else: 
                    raise ValueError
        except (ValueError, IndexError):
            continue
        else:
            break
    
    avgSec = avg(mSec,dSec)
    if avgSec > 1:
        print("%.7f" % avgSec)
    else:
        print("measurement error")  


    