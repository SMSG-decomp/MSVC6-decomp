fe_name * __cdecl name_intern_hashed(c1_u8 *text,uint hash,uint len,byte *is_new)

{
  fe_name **ppfVar1;
  fe_name *pfVar2;
  fe_name *pfVar3;
  uchar *puVar4;
  uint uVar5;
  uint uVar6;
  c1_u8 *rec;
  c1_u8 *pcVar7;
  uchar *puVar8;
  bool bVar9;
  
  ppfVar1 = g_name_hash + (hash & 0x7ff);
  uVar6 = hash >> 0x10 ^ hash & 0xffff;
  pfVar2 = (fe_name *)ppfVar1;
  pfVar3 = *ppfVar1;
  do {
    if (pfVar3 == (fe_name *)0x0) {
      if (g_name_pool.left < 0x10) {
        pool_reserve(&g_name_pool,0x10);
      }
      puVar4 = g_name_pool.cur;
      g_name_pool.left = g_name_pool.left - 0x10;
      puVar8 = g_name_pool.cur + 0x10;
      *(fe_name **)g_name_pool.cur = *ppfVar1;
      g_name_pool.cur = puVar8;
      *ppfVar1 = (fe_name *)puVar4;
      puVar8 = g_arenas[0].cur;
      g_arenas[0].cur = g_arenas[0].cur + (len + 4 & 0xfffffffc);
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      *(uchar **)(puVar4 + 4) = puVar8;
      for (uVar5 = len >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)puVar8 = *(undefined4 *)text;
        text = text + 4;
        puVar8 = puVar8 + 4;
      }
      for (uVar5 = len & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar8 = *text;
        text = text + 1;
        puVar8 = puVar8 + 1;
      }
      *(undefined1 *)(*(int *)(puVar4 + 4) + len) = 0;
      g_last_name = (fe_name *)puVar4;
      *(uint *)(puVar4 + 8) = (*(uint *)(puVar4 + 8) ^ uVar6) & 0xffff ^ *(uint *)(puVar4 + 8);
      *is_new = 1;
      return g_last_name;
    }
    if (((pfVar3->flags & 0xffff) == uVar6) && (pfVar3->text[len] == '\0')) {
      bVar9 = true;
      uVar5 = len;
      rec = text;
      pcVar7 = (c1_u8 *)pfVar3->text;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        bVar9 = *rec == *pcVar7;
        rec = rec + 1;
        pcVar7 = pcVar7 + 1;
      } while (bVar9);
      if (bVar9) {
        pfVar2->next = pfVar3->next;
        pfVar3->next = *ppfVar1;
        *ppfVar1 = pfVar3;
        g_last_name = pfVar3;
        *is_new = 0;
        return g_last_name;
      }
    }
    pfVar2 = pfVar3;
    pfVar3 = pfVar3->next;
  } while( true );
}

