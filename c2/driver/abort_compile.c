void abort_compile(void)

{
  ULONG_PTR UStack_4;
  
  backend_cleanup(0);
  RaiseException(0xe0005032,0xc0000025,1,&UStack_4);
  return;
}

