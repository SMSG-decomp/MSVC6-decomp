c2_fe_symbol * __fastcall fe_symbol_copy(c2_fe_symbol *s,int arena)

{
  c2_fe_symbol *pcVar1;
  uint uVar2;
  uint uVar3;
  uint8_t cls;
  c2_fe_symbol *pcVar4;
  
  cls = s->cls;
  if (cls == '\x04') {
    if ((s->storage & 0x4000) == 0) {
      if ((s->storage & 0x8000) != 0) {
        cls = '\x10';
      }
    }
    else {
      cls = '\x0e';
    }
  }
  pcVar1 = fe_symbol_alloc(cls,arena);
  uVar2 = fe_symbol_size((int)(char)cls);
  pcVar4 = pcVar1;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    pcVar4->next = s->next;
    s = (c2_fe_symbol *)&s->cls;
    pcVar4 = (c2_fe_symbol *)&pcVar4->cls;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)&pcVar4->next = *(undefined1 *)&s->next;
    s = (c2_fe_symbol *)((int)&s->next + 1);
    pcVar4 = (c2_fe_symbol *)((int)&pcVar4->next + 1);
  }
  return pcVar1;
}

