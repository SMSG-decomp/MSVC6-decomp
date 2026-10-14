void __fastcall enc_note_static_local(c2_fe_symbol *s)

{
  c2_enc_local *pcVar1;
  c2_enc_local *pcVar2;
  c2_enc_local *pcVar3;
  c2_enc_local *pcVar4;
  
  if ((s->cls == '\x01') && (((byte)s->storage & 0x70) == 0x10)) {
    s->attrs = s->attrs & 0xfffff7ff;
    pcVar2 = arena_alloc(1,8);
    pcVar1 = g_enc_local_list;
    pcVar2->sym = s;
    pcVar4 = (c2_enc_local *)&g_enc_local_list;
    if (pcVar1 != (c2_enc_local *)0x0) {
      do {
        pcVar3 = pcVar1;
        if (s->id <= pcVar3->sym->id) break;
        pcVar1 = pcVar3->next;
        pcVar4 = pcVar3;
      } while (pcVar3->next != (c2_enc_local *)0x0);
    }
    pcVar2->next = pcVar4->next;
    pcVar4->next = pcVar2;
  }
  return;
}

