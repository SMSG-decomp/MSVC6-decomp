void __fastcall coff_write_bytes(void *pb,uint32_t cb)

{
  c2_coff_chunk *pcVar1;
  c2_coff_chunk *pcVar2;
  c2_coff_chunk *new_chunk;
  size_t sVar3;
  uint uVar4;
  uint uVar5;
  uint32_t *copy_ptr;
  uint32_t uVar6;
  uint32_t *chunk_dst;
  uint8_t *src_cursor;
  c2_coff_data *data;
  
  if (g_coff_checksum_state != 0) {
    coff_section_checksum_add(pb,cb);
  }
  data = g_coff_current_section_data;
  if (g_coff_current_section_data->count_only != 1) {
    if (g_coff_current_section_data->buffered != 0) {
      src_cursor = pb;
      if (500 - g_coff_current_section_data->fill < cb) {
        do {
          uVar4 = 500 - data->fill;
          cb = cb - uVar4;
          pcVar1 = data->cur;
          copy_ptr = (uint32_t *)src_cursor;
          chunk_dst = (uint32_t *)(pcVar1->data + data->fill);
          for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *chunk_dst = *copy_ptr;
            copy_ptr = copy_ptr + 1;
            chunk_dst = (uint32_t *)((int)chunk_dst + 4);
          }
          for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(char *)chunk_dst = (char)*copy_ptr;
            copy_ptr = (uint32_t *)((int)copy_ptr + 1);
            chunk_dst = (uint32_t *)((int)chunk_dst + 1);
          }
          uVar6 = data->fill + uVar4;
          pb = src_cursor + uVar4;
          data->fill = uVar6;
          if (uVar6 != 500) {
            ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xdff);
          }
          new_chunk = coff_alloc_chunk();
          pcVar2 = pcVar1->next;
          data->cur = new_chunk;
          new_chunk->next = pcVar2;
          uVar6 = data->full;
          pcVar1->next = new_chunk;
          data->full = uVar6 + 500;
          data->fill = 0;
          src_cursor = pb;
        } while (500 < cb);
      }
      uVar6 = data->fill;
      copy_ptr = (uint32_t *)(data->cur->data + uVar6);
      for (uVar4 = cb >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *copy_ptr = *(undefined4 *)pb;
        pb = (uint8_t *)((int)pb + 4);
        copy_ptr = (uint32_t *)((int)copy_ptr + 4);
      }
      data->fill = uVar6 + cb;
      uVar6 = data->writes;
      for (uVar4 = cb & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(uint8_t *)copy_ptr = *(uint8_t *)pb;
        pb = (uint8_t *)((int)pb + 1);
        copy_ptr = (uint32_t *)((int)copy_ptr + 1);
      }
      data->writes = uVar6 + 1;
      return;
    }
    sVar3 = fwrite(pb,cb,1,g_coff_object_file);
    if (sVar3 != 1) {
      (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xdf4);
    }
  }
  data->fill = data->fill + cb;
  data->writes = data->writes + 1;
  return;
}

