void __cdecl
name_intern_keyword_fragment
          (int *link,int **bucket,uint length,uint hash,c1_u8 *text,uint saved_length,
          int **saved_bucket)

{
  uchar *puVar1;
  uchar *puVar2;
  fe_name *pfVar3;
  uint uVar4;
  c1_u8 *pcVar5;
  uint *cursor;
  c1_u8 *pcVar6;
  bool bVar7;
  
  do {
    do {
      pfVar3 = (fe_name *)link;
      link = (int *)pfVar3->next;
      if ((fe_name *)link == (fe_name *)0x0) {
        if (g_name_pool.left < 0x14) {
          pool_reserve(&g_name_pool,0x14);
        }
        puVar1 = g_name_pool.cur;
        g_name_pool.left = g_name_pool.left - 0x14;
        puVar2 = g_name_pool.cur + 0x14;
        *(int **)g_name_pool.cur = *bucket;
        g_name_pool.cur = puVar2;
        *bucket = (int *)puVar1;
        cursor = (uint *)g_arenas[0].cur;
        g_arenas[0].cur = g_arenas[0].cur + (length + 4 & 0xfffffffc);
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        *(uint **)(puVar1 + 4) = cursor;
        for (uVar4 = length >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *cursor = *(uint *)text;
          text = (c1_u8 *)((int)text + 4);
          cursor = cursor + 1;
        }
        for (uVar4 = length & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(char *)cursor = (char)*(uint *)text;
          text = (c1_u8 *)((int)text + 1);
          cursor = (uint *)((int)cursor + 1);
        }
        *(undefined1 *)(saved_length + *(int *)(puVar1 + 4)) = 0;
        g_last_name = (fe_name *)puVar1;
        *(uint *)(puVar1 + 8) = (*(uint *)(puVar1 + 8) ^ hash) & 0xffff ^ *(uint *)(puVar1 + 8);
        return;
      }
    } while (((((fe_name *)link)->flags & 0xffff) != hash) ||
            (((fe_name *)link)->text[length] != '\0'));
    bVar7 = true;
    pcVar5 = text;
    pcVar6 = (c1_u8 *)((fe_name *)link)->text;
    do {
      if (length == 0) break;
      length = length - 1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    length = saved_length;
    bucket = saved_bucket;
    if (bVar7) {
      pfVar3->next = ((fe_name *)link)->next;
      ((fe_name *)link)->next = (fe_name *)*saved_bucket;
      *saved_bucket = link;
      g_last_name = (fe_name *)link;
      return;
    }
  } while( true );
}

