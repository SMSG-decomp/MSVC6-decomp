void __fastcall import_init_ole(char *done)

{
  long lVar1;
  
  *done = '\x01';
  lVar1 = CoInitialize((void *)0x0);
  if (lVar1 < 0) {
    diag_fatal(100,lVar1);
  }
  return;
}

