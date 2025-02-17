export default  class StringUtils {
  public static  isNullOrEmpty(str:String) : boolean
  {
    if(str == null || str.length == 0 || str.trim().length == 0 )
    {
      return true;
    }
    return false;

  }
}