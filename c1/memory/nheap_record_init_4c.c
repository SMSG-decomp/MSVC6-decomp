c1_pch_segment * __thiscall
nheap_record_init_4c(c1_pch_segment *obj,c1_pch_segment *tmpl,c1_pch_image *image)

{
  nheap_object_base_ctor(obj,tmpl->kind,image);
  obj->file_offset = 0;
  obj->base = tmpl->base;
  obj->size = tmpl->size;
  obj->descriptor_word = tmpl->descriptor_word;
  obj->vtbl = (c1_vtbl_1065b500 *)&PTR_pch_segment_map_view_1065b500;
  obj->state = 1;
  return obj;
}

