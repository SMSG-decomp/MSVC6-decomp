int __cdecl format_snprintf(char *buf,char *fmt,int size,...)

{
  int iVar1;
  
  iVar1 = format_vsnprintf(buf,fmt,size,&stack0x00000010);
  return iVar1;
}

