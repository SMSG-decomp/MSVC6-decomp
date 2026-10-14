void __cdecl symtab_1608_insert(void *key,void *value)

{
  if (PTR_104d1608 == (c1_symtab *)0x0) {
    PTR_104d1608 = symtab_new(0x10,0,0xd,0xc,'\x01','\x01');
  }
  symtab_insert(PTR_104d1608,key,value);
  return;
}

