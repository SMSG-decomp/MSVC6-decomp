int __fastcall lookup_opcode_pair_table(c2_opcode_pair *table,int key)

{
  int iVar1;
  
  iVar1 = table->key;
  while( true ) {
    if (iVar1 == -1) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\lowerflt.c",0x4b);
    }
    if (key == iVar1) break;
    iVar1 = table[1].key;
    table = table + 1;
  }
  return table->value;
}

