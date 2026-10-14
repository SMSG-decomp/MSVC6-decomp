void __fastcall coff_write_section_data(c2_coff_data *data)

{
  c2_coff_chunk *pcVar1;
  c2_coff_chunk *pcVar2;
  size_t sVar3;
  
  if (data != (c2_coff_data *)0x0) {
    if (data->count_only != 1) {
      pcVar1 = data->cur;
      for (pcVar2 = pcVar1->next; pcVar2 != pcVar1; pcVar2 = pcVar2->next) {
        sVar3 = fwrite(pcVar2->data,500,1,g_coff_object_file);
        if (sVar3 != 1) {
          (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xe2a);
        }
      }
      if ((data->fill != 0) &&
         (sVar3 = fwrite(pcVar2->data,data->fill,1,g_coff_object_file), sVar3 != 1)) {
        (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xe2f);
      }
    }
    pcVar1 = data->cur->next;
    data->cur->next = g_coff_chunk_free_list;
    g_coff_chunk_free_list = pcVar1;
  }
  return;
}

