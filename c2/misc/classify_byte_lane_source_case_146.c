uint32_t classify_byte_lane_source_case_146(c2_operand *k,uint32_t lane_mask)

{
  if ((char)(k->u18).lo == '\0') {
    return lane_mask & 0xffff01ff | 0x100;
  }
  if ((char)((k->u18).lo >> 8) == '\0') {
    lane_mask = lane_mask | 0xff00;
  }
  return lane_mask;
}

