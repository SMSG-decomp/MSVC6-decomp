int __fastcall iv_has_non_plain_use(c2_symbol *iv)

{
  c2_list_cell *pcVar1;
  
  pcVar1 = iv->uses;
  while( true ) {
    if (pcVar1 == (c2_list_cell *)0x0) {
      return 0;
    }
    if (((pcVar1->u04).tuple)->flags13 != '\x04') break;
    pcVar1 = pcVar1->next;
  }
  return 1;
}

