c2_operand * __fastcall trip_count_as_type(c2_loop *loop,uint16_t type,c2_function *fn)

{
  c2_loop *local_4;
  
  local_4 = loop;
  get_trip_counter(loop,fn);
  fn = (c2_function *)g_trip_counter_operand;
  local_4 = (c2_loop *)g_preheader_insert_point->prev;
  convert_operand((c2_operand **)&fn,type,(c2_tuple **)&local_4);
  return (c2_operand *)fn;
}

