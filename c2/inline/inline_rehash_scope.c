void __fastcall inline_rehash_scope(void *scope,void **buckets)

{
  char *pcVar1;
  uint8_t uVar2;
  c2_fe_symbol *pcVar3;
  c2_fe_symbol *s;
  uint32_t uVar4;
  int local_8;
  
  local_8 = 0x400;
  do {
    buckets = buckets + 1;
    pcVar3 = *buckets;
    while (s = pcVar3, s != (c2_fe_symbol *)0x0) {
      uVar2 = s->cls;
      pcVar3 = s->next;
      if ((uVar2 != '\x01') || (((byte)s->storage & 0x70) != 0x30)) {
        uVar4 = fe_symbol_next_id();
        s->id = uVar4;
        if ((uVar2 == '\x01') && (((byte)s->storage & 0x70) == 0x10)) {
          pcVar1 = (char *)((int)&s->refcount + 2);
          *pcVar1 = *pcVar1 + '\x01';
        }
        scope_hash_insert(scope,s);
      }
    }
    *buckets = (void *)0x0;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  return;
}

