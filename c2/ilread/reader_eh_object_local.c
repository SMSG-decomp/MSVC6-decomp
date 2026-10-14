c2_fe_symbol * __fastcall
reader_eh_object_local(c2_function *fn,int key,uint32_t type_kind,int size)

{
  c2_reader_eh_local *pcVar1;
  c2_reader_eh_local *pcVar2;
  c2_fe_symbol *s;
  uint32_t uVar3;
  uint uVar4;
  c2_list_cell *pcVar5;
  
  pcVar1 = g_reader_eh_object_locals;
  while( true ) {
    if (pcVar1 == (c2_reader_eh_local *)0x0) {
      pcVar2 = arena_alloc(1,0xc);
      pcVar1 = pcVar2;
      pcVar2->next = g_reader_eh_object_locals;
      g_reader_eh_object_locals = pcVar1;
      pcVar2->key = key;
      s = fe_symbol_alloc('\x01',1);
      s->name = (char *)0x0;
      uVar3 = fe_symbol_next_id();
      s->id = uVar3;
      s->size = size;
      uVar4 = s->storage & 0xfffffa1f | 0x210;
      s->role = '&';
      s->storage = (uVar4 ^ type_kind) & 0xf ^ uVar4 | 0x80000;
      fe_symbol_choose_section(s);
      fe_symbol_assign_frame(s);
      scope_hash_insert(fn->scope,s);
      pcVar2->local = s;
      pcVar5 = arena_alloc(1,8);
      (pcVar5->u04).fe = s;
      pcVar5->next = g_reader_new_locals;
      g_reader_new_locals = pcVar5;
      return s;
    }
    if (pcVar1->key == key) break;
    pcVar1 = pcVar1->next;
  }
  return pcVar1->local;
}

