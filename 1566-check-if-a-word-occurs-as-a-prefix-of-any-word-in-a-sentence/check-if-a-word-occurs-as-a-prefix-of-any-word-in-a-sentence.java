class Solution {
    public int isPrefixOfWord(String sentence, String d) {
        ArrayList<String>word=new ArrayList<>();
        String value="";
        for(int i=0;i<sentence.length();i++){
            value+=sentence.charAt(i);
            if(sentence.charAt(i)==' ')
            {
                word.add(value);
                value="";
            }

        }
        int count=0;
        word.add(value);
        
        int j=0;
        for(String ans:word){
           if(ans.length()<d.length()){

           }
           else if(ans.length()>=d.length()){
            for(int i=0;i<d.length();i++){
                if(ans.charAt(i)==d.charAt(i))
                {
                    count++;
                }
                else{
                    count=0;
                    break;
                }
            }
            if(count==d.length()){
                return j+1;
            }
           }
           j++;
        }
        return -1;
    }
}