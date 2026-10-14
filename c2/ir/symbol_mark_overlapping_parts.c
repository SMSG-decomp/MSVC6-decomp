void __fastcall symbol_mark_overlapping_parts(c2_symbol *sym,c2_tuple *t)

{
  c2_symbol *pcVar1;
  
  pcVar1 = sym->storage;
  do {
    if (pcVar1 == (c2_symbol *)0x0) {
      return;
    }
    if (pcVar1 == sym) {
LAB_1070179c:
      pcVar1->def = t;
    }
    else if ((pcVar1->offset < sym->size + sym->offset) &&
            (sym->offset < pcVar1->size + pcVar1->offset)) goto LAB_1070179c;
    pcVar1 = pcVar1->part_next;
  } while( true );
}

