char * __cdecl format_buffer_reserve(int buf,int at_end,uint n)

{
  uint uVar1;
  c1_u32 cVar2;
  c1_text_buffer *pcVar3;
  uint *block;
  uint *block_2;
  uint uVar4;
  uint uVar5;
  uint *cursor;
  uint *cursor_2;
  uint *cursor_3;
  uint *dst;
  uint *cursor_4;
  uint *dst_2;
  
  pcVar3 = format_buffer_find(buf);
  if (pcVar3 != (c1_text_buffer *)0x0) {
    if (at_end == 0) {
      if (pcVar3->front < n) {
        uVar1 = pcVar3->capacity + 0x20 + n;
        block_2 = mem_xmalloc(uVar1);
        cursor_4 = block_2;
        for (uVar4 = uVar1 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *cursor_4 = 0;
          cursor_4 = cursor_4 + 1;
        }
        for (uVar4 = uVar1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)cursor_4 = 0;
          cursor_4 = (uint *)((int)cursor_4 + 1);
        }
        uVar5 = (pcVar3->end - pcVar3->front) - 1;
        cursor_2 = (uint *)(pcVar3->data + pcVar3->front + 1);
        dst_2 = (uint *)((int)block_2 + n + 0x21);
        for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *dst_2 = *cursor_2;
          cursor_2 = cursor_2 + 1;
          dst_2 = dst_2 + 1;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(char *)dst_2 = (char)*cursor_2;
          cursor_2 = (uint *)((int)cursor_2 + 1);
          dst_2 = (uint *)((int)dst_2 + 1);
        }
        mem_free(pcVar3->data);
        pcVar3->data = (char *)block_2;
        pcVar3->end = pcVar3->end + n + 0x20;
        pcVar3->capacity = uVar1;
        pcVar3->front = n + 0x20;
      }
      cVar2 = pcVar3->front;
      pcVar3->front = cVar2 - n;
      return pcVar3->data + cVar2;
    }
    if (at_end == 1) {
      if (pcVar3->capacity <= pcVar3->end + n) {
        uVar1 = n + 0x20 + pcVar3->capacity;
        block = mem_xmalloc(uVar1);
        cursor_3 = block;
        for (uVar4 = uVar1 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *cursor_3 = 0;
          cursor_3 = cursor_3 + 1;
        }
        for (uVar4 = uVar1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)cursor_3 = 0;
          cursor_3 = (uint *)((int)cursor_3 + 1);
        }
        uVar4 = pcVar3->end;
        cursor = (uint *)pcVar3->data;
        dst = block;
        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *dst = *cursor;
          cursor = cursor + 1;
          dst = dst + 1;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(char *)dst = (char)*cursor;
          cursor = (uint *)((int)cursor + 1);
          dst = (uint *)((int)dst + 1);
        }
        mem_free(pcVar3->data);
        pcVar3->data = (char *)block;
        pcVar3->capacity = uVar1;
      }
      cVar2 = pcVar3->end;
      pcVar3->end = cVar2 + n;
      return pcVar3->data + cVar2;
    }
  }
  return (char *)0x0;
}

