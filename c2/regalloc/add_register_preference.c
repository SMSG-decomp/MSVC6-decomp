c2_register_preference * __fastcall
add_register_preference(c2_live_range *lr,c2_register_descriptor *reg)

{
  c2_fe_symbol *pcVar1;
  c2_fe_symbol *pcVar2;
  c2_register_descriptor *pcVar3;
  
  pcVar3 = lr->colour;
  if (pcVar3 == (c2_register_descriptor *)0x0) {
    pcVar1 = (c2_fe_symbol *)lr->prefs;
    for (pcVar2 = pcVar1; pcVar2 != (c2_fe_symbol *)0x0; pcVar2 = pcVar2->next) {
      if (*(c2_register_descriptor **)&pcVar2->cls == reg) {
        if (pcVar2 != (c2_fe_symbol *)0x0) {
          pcVar2->storage_sym = (c2_symbol *)((int)&pcVar2->storage_sym->fe + 1);
          return (c2_register_preference *)pcVar2;
        }
        break;
      }
    }
    pcVar3 = arena_alloc(4,0xc);
    *(c2_register_descriptor **)&pcVar3->cls = reg;
    pcVar3->storage = (c2_symbol *)0x1;
    pcVar3->fe = pcVar1;
    lr->prefs = (c2_register_preference *)pcVar3;
  }
  return (c2_register_preference *)pcVar3;
}

