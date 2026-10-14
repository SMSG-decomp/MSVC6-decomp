void __fastcall fatal_error_errno(int id,char *message,char *file_name)

{
  char *pcVar1;
  
  pcVar1 = _strerror((char *)0x0);
  fatal_error(id,message,file_name,pcVar1);
}

