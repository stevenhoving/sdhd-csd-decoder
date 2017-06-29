#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdint>

#pragma pack(push, 1)
#if 0
struct csd
{
    uint8_t CSD_STRUCTURE       : 2;    // 2         R      [127:126]                01
    uint8_t padding_0           : 6;    // 6         R      [125:120]              All '0'
    uint8_t TAAC                : 8;    // 8         R      [119:112]           0_0001_110(1ms)
    uint8_t NSAC                : 8;    // 8         R[111:104]               00000000
    uint8_t TRAN_SPEED          : 8;    // 8         R      [103:96]            0_0110_010(25Mbps)
    uint16_t CCC                : 12;   // 12        R      [95:84]            0_1_0_1_1_0_1_1_0_1_0_1
    uint8_t READ_BL_LEN         : 4;    // 4         R      [83:80] | 1001 | 1001
    uint8_t READ_BL_PARTIAL     : 1;    // 1         R      [79:79]         0
    uint8_t WRITE_BLK_MISALIGN  : 1;    // 1         R      [78:78]         0
    uint8_t READ_BLK_MISALIGN   : 1;    // 1         R      [77:77]         0
    uint8_t DSR_IMP             : 1;    // 1         R      [76:76]         0
    uint8_t padding_1           : 6;    // 6         R      [75:70]         All '0'
    uint32_t C_SIZE             : 22;   // 22        R      [69:48]         0x1DFF 0x3BFF
    uint8_t padding_2           : 1;    // 1         R      [47:47]         0
    uint8_t ERASE_BLK_EN        : 1;    // 1         R      [46:46]         1
    uint8_t SECTOR_SIZE         : 7;    // 7         R      [45:39]         11_1111_1
    uint8_t WP_GRP_SIZE         : 7;    // 7         R      [38:32]         000_0000
    uint8_t WP_GRP_ENABLE       : 1;    // 1         R      [31:31]         0
    uint8_t padding_3           : 2;    // 2         R      [30:29]         00
    uint8_t R2W_FACTOR          : 3;    // 3         R      [28:26]         010
    uint8_t WRITE_BL_LEN        : 4;    // 4         R      [25:22]         1001
    uint8_t WRITE_BL_PARTIAL    : 1;    // 1         R      [21:21]         0
    uint8_t padding_4           : 2;    // 2         R      [20:16]         All '0'
    uint8_t FILE_FORMAT_GRP     : 1;    // 1         R      [15:15]         0
    uint8_t COPY                : 1;    // 1         R/W(1) [14:14]         0
    uint8_t PERM_WRITE_PROTECT  : 1;    // 1         R/W(1) [13:13]         0
    uint8_t TMP_WRITE_PROTECT   : 1;    // 1         R/W    [12:12]         0
    uint8_t FILE_FORMAT         : 2;    // 2         R      [11:10]         00
    uint8_t padding_5           : 2;    // 2         R      [9:8]           All '0'
    uint8_t CRC                 : 7;    // 7         R/W    [7:1](CRC)
    uint8_t padding_6           : 1;    // 1          -     [0:0]           1
};

#else

#if 0
struct csd
{
    uint8_t padding_6           : 1;    // 1          -     [0:0]           1
    uint8_t CRC                 : 7;    // 7         R/W    [7:1](CRC)
    uint8_t padding_5           : 2;    // 2         R      [9:8]           All '0'
    uint8_t FILE_FORMAT         : 2;    // 2         R      [11:10]         00
    uint8_t TMP_WRITE_PROTECT   : 1;    // 1         R/W    [12:12]         0
    uint8_t PERM_WRITE_PROTECT  : 1;    // 1         R/W(1) [13:13]         0
    uint8_t COPY                : 1;    // 1         R/W(1) [14:14]         0
    uint8_t FILE_FORMAT_GRP     : 1;    // 1         R      [15:15]         0
    uint8_t padding_4           : 2;    // 2         R      [20:16]         All '0'
    uint8_t WRITE_BL_PARTIAL    : 1;    // 1         R      [21:21]         0
    uint8_t WRITE_BL_LEN        : 4;    // 4         R      [25:22]         1001
    uint8_t R2W_FACTOR          : 3;    // 3         R      [28:26]         010
    uint8_t padding_3           : 2;    // 2         R      [30:29]         00
    uint8_t WP_GRP_ENABLE       : 1;    // 1         R      [31:31]         0
    uint8_t WP_GRP_SIZE         : 7;    // 7         R      [38:32]         000_0000
    uint8_t SECTOR_SIZE         : 7;    // 7         R      [45:39]         11_1111_1
    uint8_t ERASE_BLK_EN        : 1;    // 1         R      [46:46]         1
    uint8_t padding_2           : 1;    // 1         R      [47:47]         0
    uint32_t C_SIZE             : 22;   // 22        R      [69:48]         0x1DFF 0x3BFF
    uint8_t padding_1           : 6;    // 6         R      [75:70]         All '0'
    uint8_t DSR_IMP             : 1;    // 1         R      [76:76]         0
    uint8_t READ_BLK_MISALIGN   : 1;    // 1         R      [77:77]         0
    uint8_t WRITE_BLK_MISALIGN  : 1;    // 1         R      [78:78]         0
    uint8_t READ_BL_PARTIAL     : 1;    // 1         R      [79:79]         0
    uint8_t READ_BL_LEN         : 4;    // 4         R      [83:80] | 1001 | 1001
    uint16_t CCC                : 12;   // 12        R      [95:84]            0_1_0_1_1_0_1_1_0_1_0_1
    uint8_t TRAN_SPEED          : 8;    // 8         R      [103:96]            0_0110_010(25Mbps)
    uint8_t NSAC                : 8;    // 8         R      [111:104]               00000000
    uint8_t TAAC                : 8;    // 8         R      [119:112]           0_0001_110(1ms)
    uint8_t padding_0           : 6;    // 6         R      [125:120]              All '0'
    uint8_t CSD_STRUCTURE       : 2;    // 2         R      [127:126]                01
};

#endif

#endif

#pragma pack(pop)

static char *sd_csd_ver[] = { "v1.0", "v2.0" };
static char *mmc_csd_ver[] = { "v1.0", "v1.1", "v1.2", "Ver. in EXT_CSD" };
static char *mmc_cmd_cls[] = { "basic", "stream read", "block read",
    "stream write", "block write", "erase", "write prot", "lock card",
    "app-spec", "I/O", "rsv.", "rsv." };
static char *sd_cmd_cls[] = { "basic", "rsv.", "block read",
    "rsv.", "block write", "erase", "write prot", "lock card",
    "app-spec", "I/O", "switch", "rsv." };


std::vector<uint32_t> fromhex(const std::string & s)
{
    static std::map<char, int> lookupTable = {
        { '0', 0x0 }, { '1', 0x1 }, { '2', 0x2 }, { '3', 0x3 }, { '4', 0x4 },
        { '5', 0x5 }, { '6', 0x6 }, { '7', 0x7 }, { '8', 0x8 }, { '9', 0x9 },
        { 'a', 0xa }, { 'b', 0xb }, { 'c', 0xc }, { 'd', 0xd }, { 'e', 0xe }, { 'f', 0xf },
        { 'A', 0xA }, { 'B', 0xB }, { 'C', 0xC }, { 'D', 0xD }, { 'E', 0xE }, { 'F', 0xF }
    };

    if (s.size() & 0x1)
        printf("odd hex string size... which is odd\n");

    std::vector<uint32_t> result;
    for (size_t i = 0; i < s.size(); i += 8)
        result.push_back(
            lookupTable[s[i + 0]] << 28 |
            lookupTable[s[i + 1]] << 24 |
            lookupTable[s[i + 2]] << 20 |
            lookupTable[s[i + 3]] << 16 |
            lookupTable[s[i + 4]] << 12 |
            lookupTable[s[i + 5]] << 8 |
            lookupTable[s[i + 6]] << 4 |
            lookupTable[s[i + 7]] << 0
        );

    return result;
}

uint32_t unstuff_bits(uint32_t *resp, uint32_t start, uint32_t size)
{
    const uint32_t __mask = (1 << (size)) - 1;
    const int __off = 3 - ((start) / 32);
    const int __shft = (start)& 31;
    uint32_t __res;

    __res = resp[__off] >> __shft;
    if ((size)+__shft >= 32)
        __res |= resp[__off - 1] << (32 - __shft);
    return __res & __mask;
}

static const unsigned int tran_exp[] = {
    10000, 100000, 1000000, 10000000,
    0, 0, 0, 0
};

static const unsigned char tran_mant[] = {
    0, 10, 12, 13, 15, 20, 25, 30,
    35, 40, 45, 50, 55, 60, 70, 80,
};

static const unsigned int tacc_exp[] = {
    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000,
};

static const unsigned int tacc_mant[] = {
    0, 10, 12, 13, 15, 20, 25, 30,
    35, 40, 45, 50, 55, 60, 70, 80,
};

/*
static const unsigned int sd_au_size[] = {
    0, SZ_16K / 512, SZ_32K / 512, SZ_64K / 512,
    SZ_128K / 512, SZ_256K / 512, SZ_512K / 512, SZ_1M / 512,
    SZ_2M / 512, SZ_4M / 512, SZ_8M / 512, (SZ_8M + SZ_4M) / 512,
    SZ_16M / 512, (SZ_16M + SZ_8M) / 512, SZ_32M / 512, SZ_64M / 512,
};
*/

struct mmc_csd {
    unsigned char       structure;
    unsigned char       mmca_vsn;
    unsigned short      cmdclass;
    unsigned short      tacc_clks;
    unsigned int        tacc_ns;
    unsigned int        c_size;
    unsigned int        r2w_factor;
    unsigned int        max_dtr;
    unsigned int        erase_size;        /* In sectors */
    unsigned int        read_blkbits;
    unsigned int        write_blkbits;
    unsigned int        capacity;
    unsigned int        read_partial : 1,
                        read_misalign : 1,
                        write_partial : 1,
                        write_misalign : 1,
                        dsr_imp : 1;
};

static int mmc_decode_csd(std::vector<uint32_t> raw_csd)
{
    unsigned int csd_struct;
    uint32_t *resp = raw_csd.data();

    csd_struct = unstuff_bits(resp, 126, 2);
    switch (csd_struct) {
    case 0:
    {
        // according to the Toshiba sd spec
        printf("## CSD Version 1.0-1.10 ##\n");
        printf("CSD structure:                  0x%X\n", unstuff_bits(resp, 126, 2));
        printf("Reserved:                       0x%X\n", unstuff_bits(resp, 120, 6));
        printf("Data read access-time 1:        0x%X\n", unstuff_bits(resp, 112, 8));
        printf("Data read access-time 2:        0x%X\n", unstuff_bits(resp, 104, 8));
        printf("Max. bus clock frequency:       0x%X\n", unstuff_bits(resp,  96, 8));
        printf("Card command classes:           0x%X\n", unstuff_bits(resp,  95, 12));
        printf("Max. read data block length:    0x%X\n", unstuff_bits(resp,  80, 4));
        printf("Partial blocks for read allowed:0x%X\n", unstuff_bits(resp,  79, 1));
        printf("Write block misalignment:       0x%X\n", unstuff_bits(resp,  78, 1));
        printf("Read block misalignment:        0x%X\n", unstuff_bits(resp,  77, 1));
        printf("DSR implemented:                0x%X\n", unstuff_bits(resp,  76, 1));
        printf("Reserved:                       0x%X\n", unstuff_bits(resp,  70, 6));
        printf("Card size:                      0x%X\n", unstuff_bits(resp,  48, 22));
        printf("Reserved:                       0x%X\n", unstuff_bits(resp,  47, 1));
        printf("ERASE_BLK_EN:                   0x%X\n", unstuff_bits(resp,  46, 1));
        printf("SECTOR_SIZE:                    0x%X\n", unstuff_bits(resp,  39, 7));
        printf("Write protect group size:       0x%X\n", unstuff_bits(resp,  32, 7));
        printf("Write protect group enable:     0x%X\n", unstuff_bits(resp,  31, 1));
        printf("Reserved:                       0x%X\n", unstuff_bits(resp,  29, 2));
        printf("Write speed factor:             0x%X\n", unstuff_bits(resp,  26, 3));
        printf("Max. write data block length:   0x%X\n", unstuff_bits(resp,  22, 4));
        printf("Part. blocks for write allowed: 0x%X\n", unstuff_bits(resp,  21, 1));
        printf("Reserved:                       0x%X\n", unstuff_bits(resp,  16, 2));
        printf("File format group:              0x%X\n", unstuff_bits(resp,  15, 1));
        printf("Copy flag (OTP):                0x%X\n", unstuff_bits(resp,  14, 1));
        printf("Permanent write protection:     0x%X\n", unstuff_bits(resp,  13, 1));
        printf("Temporary write protection:     0x%X\n", unstuff_bits(resp,  12, 1));
        printf("File format:                    0x%X\n", unstuff_bits(resp,  20, 2));
        printf("Reserved:                       0x%X\n", unstuff_bits(resp,   8, 2));
        printf("CRC:                            0x%X\n", unstuff_bits(resp,   1, 7));
        printf("Reserved:                       0x%X\n", unstuff_bits(resp,   0, 1));
    } break;

    case 1:
    {
        // according to the Samsung sdhc spec
        printf("## CSD Version 2.0 ##\n");
        printf("CSD structure:                  0x%X\n", unstuff_bits(resp, 126, 2));
        printf("Sys Spec ver:                   0x%X\n", unstuff_bits(resp, 122, 4));
        printf("Reserved:                       0x%X\n", unstuff_bits(resp, 120, 2));
        printf("Data read access-time 1:        0x%X\n", unstuff_bits(resp, 112, 8));
        printf("Data read access-time 2:        0x%X\n", unstuff_bits(resp, 104, 8));
        printf("Max. bus clock freq:            0x%X\n", unstuff_bits(resp,  96, 8));
        printf("Card command classes:           0x%X\n", unstuff_bits(resp,  84, 12));
        printf("Max.read data block length:     0x%X\n", unstuff_bits(resp,  80, 4));
        printf("Partial blocks for read allowed:0x%X\n", unstuff_bits(resp,  79, 1));
        printf("Write block misalignment:       0x%X\n", unstuff_bits(resp,  78, 1));
        printf("Read block misalignment:        0x%X\n", unstuff_bits(resp,  77, 1));
        printf("DSR implemented:                0x%X\n", unstuff_bits(resp,  76, 1));
        printf("Reserved                        0x%X\n", unstuff_bits(resp,  74, 2));
        printf("Card size:                      0x%X\n", unstuff_bits(resp,  62, 12));
        printf("Min.read current @ VDD min:     0x%X\n", unstuff_bits(resp,  59, 3));
        printf("Max.read current @ VDD max:     0x%X\n", unstuff_bits(resp,  56, 3));
        printf("Min.write current @ VDD min:    0x%X\n", unstuff_bits(resp,  53, 3));
        printf("Max.write current @ VDD max:    0x%X\n", unstuff_bits(resp,  50, 3));
        printf("Card size multiplier:           0x%X\n", unstuff_bits(resp,  47, 3));
        printf("Erase group size:               0x%X\n", unstuff_bits(resp,  42, 5));
        printf("Erase group size multiplier:    0x%X\n", unstuff_bits(resp,  37, 5));
        printf("Write protect group size:       0x%X\n", unstuff_bits(resp,  32, 5));
        printf("Write protect group enable:     0x%X\n", unstuff_bits(resp,  31, 1));
        printf("Manufacturer default:           0x%X\n", unstuff_bits(resp,  29, 2));
        printf("Write speed factor:             0x%X\n", unstuff_bits(resp,  26, 3));
        printf("Max.write data block length:    0x%X\n", unstuff_bits(resp,  22, 4));
        printf("Part. blocks for write allowed: 0x%X\n", unstuff_bits(resp,  21, 1));
        printf("Reserved:                       0x%X\n", unstuff_bits(resp,  17, 4));
        printf("Content protection application: 0x%X\n", unstuff_bits(resp,  16, 1));
        printf("File format group:              0x%X\n", unstuff_bits(resp,  15, 1));
        printf("Copy flag(OTP):                 0x%X\n", unstuff_bits(resp,  14, 1));
        printf("Permanent write protection:     0x%X\n", unstuff_bits(resp,  13, 1));
        printf("Temporary write protection:     0x%X\n", unstuff_bits(resp,  12, 1));
        printf("File format:                    0x%X\n", unstuff_bits(resp,  10, 2));
        printf("ECC code:                       0x%X\n", unstuff_bits(resp,   8, 2));
        printf("CRC:                            0x%X\n", unstuff_bits(resp,   1, 7));
        printf("Not used                        0x%X\n", unstuff_bits(resp,   0, 1));
    }break;
    default:
        printf("unrecognized CSD structure version\n");
        return -1;
    }

    return 0;
}

static int mmc_decode_scr(std::vector<uint32_t> raw_scr)
{
    uint32_t *resp = raw_scr.data();

    printf("## SCR Version 1.0-2.00 ##\n");
    printf("SCR structure:                  0x%X\n", unstuff_bits(resp, 60, 4));
    printf("SD Spec:                        0x%X\n", unstuff_bits(resp, 56, 4));
    printf("DATA_STAT_AFTER_ERASE:          0x%X\n", unstuff_bits(resp, 55, 1));
    printf("SD_SECURITY:                    0x%X\n", unstuff_bits(resp, 52, 3));
    printf("SD_BUS_WIDTHS:                  0x%X\n", unstuff_bits(resp, 48, 4));
    printf("Reserved:                       0x%X\n", unstuff_bits(resp, 32, 16));
    printf("Manufacture usage:              0x%X\n", unstuff_bits(resp, 0, 32));

    return 0;
}

void mmc_decode_cid(std::vector<uint32_t> raw_scr)
{
    uint32_t *resp = raw_scr.data();

    printf("## CID ##\n");
    printf("manfid:                         0x%X\n", unstuff_bits(resp, 120, 8));
    printf("oemid:                          0x%X\n", unstuff_bits(resp, 104, 16));
    printf("prod_name[0]:                   0x%X (%c)\n", unstuff_bits(resp,  96, 8), unstuff_bits(resp,  96, 8));
    printf("prod_name[1]:                   0x%X (%c)\n", unstuff_bits(resp,  88, 8), unstuff_bits(resp,  88, 8));
    printf("prod_name[2]:                   0x%X (%c)\n", unstuff_bits(resp,  80, 8), unstuff_bits(resp,  80, 8));
    printf("prod_name[3]:                   0x%X (%c)\n", unstuff_bits(resp,  72, 8), unstuff_bits(resp,  72, 8));
    printf("prod_name[4]:                   0x%X (%c)\n", unstuff_bits(resp,  64, 8), unstuff_bits(resp,  64, 8));
    printf("hwrev:                          0x%X\n", unstuff_bits(resp,  60, 4));
    printf("fwrev:                          0x%X\n", unstuff_bits(resp,  56, 4));
    printf("serial:                         0x%X\n", unstuff_bits(resp,  24, 32));
    printf("year:                           %u\n",   unstuff_bits(resp,  12, 8) + 2000);
    printf("month:                          %u\n",   unstuff_bits(resp,   8, 4));
    printf("CRC:                            0x%X\n", unstuff_bits(resp,   1, 7));
    printf("Reserved:                       0x%X\n", unstuff_bits(resp,   0, 1));
}

int main()
{
    //mmc_decode_csd(fromhex("400e00325b5900003a477f800a400000"));
    //printf("\n");
    //mmc_decode_scr(fromhex("02b5800034027102"));
    //printf("\n");
    //mmc_decode_cid(fromhex("02544d534530384706c9f3ed3600ea00"));

    // \todo convert this so it eats these values by command line
    mmc_decode_csd(fromhex("400e00325b59000039b77f800a400000"));
    printf("\n");
    mmc_decode_scr(fromhex("0235800001000000"));
    printf("\n");
    mmc_decode_cid(fromhex("02544d534130384714156839f500f400"));
}
