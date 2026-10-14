void coff_read_extern_names(void)

{
  byte bVar1;
  uint8_t uVar2;
  c2_fe_symbol *pcVar3;
  char *pcVar4;
  uint8_t *puVar5;
  uint local_68;
  uint8_t local_64;
  uint8_t local_63 [99];
  
  bVar1 = prevobj_read_byte();
  while (bVar1 != 0xff) {
    local_68 = (uint)bVar1;
    puVar5 = &local_64;
    local_64 = prevobj_read_byte();
    uVar2 = local_64;
    while (uVar2 != '\0') {
      puVar5 = puVar5 + 1;
      uVar2 = prevobj_read_byte();
      *puVar5 = uVar2;
    }
    uVar2 = prevobj_read_byte();
    if (uVar2 == '\x01') {
      g_fe_forced_local_id = local_68 - 0x81;
      pcVar3 = fe_symbol_new_local_cur(3,4,2,0,'\x02',0);
      g_fe_forced_local_id = 0;
      g_extern_name_hash[local_68] = pcVar3;
      pcVar4 = arena_strdup((char *)&local_64,0);
      pcVar3->name = pcVar4;
      pcVar3->role = '\0';
    }
    else {
      pcVar3 = fe_symbol_alloc('\x04',0);
      pcVar3->cls = '\x04';
      g_extern_name_hash[local_68] = pcVar3;
      pcVar3->id = local_68 - 0x81;
      pcVar4 = arena_strdup((char *)&local_64,0);
      pcVar3->name = pcVar4;
      pcVar3->storage = pcVar3->storage & 0xfffff947 | 0x147;
      pcVar3->attrs = 0;
      pcVar3->flags31 = pcVar3->flags31 & 0xfc;
      fe_symbol_hash_insert(pcVar3,0);
    }
    bVar1 = prevobj_read_byte();
  }
  return;
}

