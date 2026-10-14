int __fastcall symbol_has_no_register_overlap(c2_symbol *s)

{
  c2_symbol *pcVar1;
  int iVar2;
  
  pcVar1 = s->storage;
  do {
    if (pcVar1 == (c2_symbol *)0x0) {
      return 1;
    }
    if (pcVar1 != s) {
      if (((pcVar1->offset < s->size + s->offset) && (s->offset < pcVar1->size + pcVar1->offset)) &&
         (iVar2 = type_is_register_candidate(pcVar1->type), iVar2 != 0)) {
        return 0;
      }
    }
    pcVar1 = pcVar1->part_next;
  } while( true );
}

