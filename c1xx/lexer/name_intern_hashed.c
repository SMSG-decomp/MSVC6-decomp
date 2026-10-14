void * __cdecl name_intern_hashed(c1_u8 *text,uint hash,uint len,byte *is_new)

{
  uchar *puVar1;
  uint uVar2;
  uint uVar3;
  c1_u8 *pcVar4;
  c1_u8 *pcVar5;
  bool bVar6;
  fe_name *prev;
  fe_name *name_rec;
  fe_name *bucket;
  uchar *new_rec;
  
  bucket = (fe_name *)(g_name_hash + (hash & 0x7ff));
  uVar3 = hash >> 0x10 ^ hash & 0xffff;
  prev = bucket;
  name_rec = bucket->next;
  do {
    if (name_rec == (fe_name *)0x0) {
      if (g_name_pool_left < 0x10) {
        pool_reserve((c1xx_pool *)&g_name_pool,0x10);
      }
      new_rec = g_name_pool;
      g_name_pool_left = g_name_pool_left - 0x10;
      puVar1 = g_name_pool + 0x10;
      *(fe_name **)g_name_pool = bucket->next;
      g_name_pool = puVar1;
      bucket->next = (fe_name *)new_rec;
      pcVar4 = g_arenas[0].cur;
      g_arenas[0].cur = g_arenas[0].cur + (len + 4 & 0xfffffffc);
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      *(c1_u8 **)(new_rec + 4) = pcVar4;
      for (uVar2 = len >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined4 *)pcVar4 = *(undefined4 *)text;
        text = text + 4;
        pcVar4 = pcVar4 + 4;
      }
      for (uVar2 = len & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar4 = *text;
        text = text + 1;
        pcVar4 = pcVar4 + 1;
      }
      *(undefined1 *)(*(int *)(new_rec + 4) + len) = 0;
      g_last_name = (fe_name *)new_rec;
      *(uint *)(new_rec + 8) = (*(uint *)(new_rec + 8) ^ uVar3) & 0xffff ^ *(uint *)(new_rec + 8);
      *is_new = 1;
      return g_last_name;
    }
    if (((name_rec->flags & 0xffff) == uVar3) && (name_rec->text[len] == '\0')) {
      bVar6 = true;
      uVar2 = len;
      pcVar4 = text;
      pcVar5 = (c1_u8 *)name_rec->text;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        prev->next = name_rec->next;
        name_rec->next = bucket->next;
        bucket->next = name_rec;
        g_last_name = name_rec;
        *is_new = 0;
        return g_last_name;
      }
    }
    prev = name_rec;
    name_rec = name_rec->next;
  } while( true );
}

