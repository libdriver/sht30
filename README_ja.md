[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SHT30

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/sht30/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

SHT30は、Sensirionの次世代の温度および湿度センサーです。これは、Sensirionの新しい湿度および温度プラットフォームの中心にある新しいCMOSensセンサーチップ上に構築されています。 SHT30は、前モデルと比較して、インテリジェンス、信頼性、および精度の仕様が向上しています。その機能には、強化された信号処理、2つの特徴的でユーザーが選択可能なIICアドレス、および最大1MHzの通信速度が含まれます。 DFNパッケージのフットプリントは2.5x2.5 mm2で、高さは0.9mmを維持しています。これにより、SHT30をさまざまなアプリケーションに統合できます。さらに、2.4 V〜5.5 Vの広い電源電圧範囲により、さまざまな組み立て状況との互換性が保証されます。全体として、SHT30には、湿度センサー業界のリーダーであるSensirionに関する15年の知識が組み込まれています。

LibDriver SHT30は、LibDriverによって発売されたSHT30の全機能ドライバーであり、温度と湿度の連続モード読み取りおよび温度と湿度の単一モード読み取りの機能を提供します。 LibDriverはMISRAに準拠しています。

### 目次

  - [説明](#説明)
  - [インストール](#インストール)
  - [使用](#使用)
    - [example basic](#example-basic)
    - [example shot](#example-shot)
  - [ドキュメント](#ドキュメント)
  - [貢献](#貢献)
  - [著作権](#著作権)
  - [連絡して](#連絡して)

### 説明

/ srcディレクトリには、LibDriver SHT30のソースファイルが含まれています。

/ interfaceディレクトリには、LibDriver SHT30用のプラットフォームに依存しないIICバステンプレートが含まれています。

/ testディレクトリには、チップの必要な機能を簡単にテストできるLibDriver SHT30ドライバーテストプログラムが含まれています。

/ exampleディレクトリには、LibDriver SHT30プログラミング例が含まれています。

/ docディレクトリには、LibDriver SHT30オフラインドキュメントが含まれています。

/ datasheetディレクトリには、SHT30データシートが含まれています。

/ projectディレクトリには、一般的に使用されるLinuxおよびマイクロコントローラー開発ボードのプロジェクトサンプルが含まれています。 すべてのプロジェクトは、デバッグ方法としてシェルスクリプトを使用しています。詳細については、各プロジェクトのREADME.mdを参照してください。

/ misraはLibDriver misraコードスキャン結果を含む。

### インストール

/ interfaceディレクトリにあるプラットフォームに依存しないIICバステンプレートを参照して、指定したプラットフォームのIICバスドライバを完成させます。

/src ディレクトリ、プラットフォームのインターフェイス ドライバー、および独自のドライバーをプロジェクトに追加します。デフォルトのサンプル ドライバーを使用する場合は、/example ディレクトリをプロジェクトに追加します。

### 使用

/example ディレクトリ内のサンプルを参照して、独自のドライバーを完成させることができます。 デフォルトのプログラミング例を使用したい場合の使用方法は次のとおりです。

#### example basic

```C
#include "driver_sht30_basic.h"

uint8_t res;
uint8_t i;
float temperature;
float humidity;

res = sht30_basic_init(SHT30_ADDRESS_0);
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    sht30_interface_delay_ms(1000);
    res = sht30_basic_read((float *)&temperature, (float *)&humidity);
    if (res != 0)
    {
        (void)sht30_basic_deinit();

        return 1;
    }
    sht30_interface_debug_print("sht30: temperature is %0.2fC.\n", temperature);
    sht30_interface_debug_print("sht30: humidity is %0.2f%%.\n", humidity);
    
    ...
    
}

...

(void)sht30_basic_deinit();

return 0;
```

#### example shot

```c
#include "driver_sht30_shot.h"

uint8_t res;
uint8_t i;
float temperature;
float humidity;

res = sht30_shot_init(SHT30_ADDRESS_0);
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    sht30_interface_delay_ms(1000);
    res = sht30_shot_read((float *)&temperature, (float *)&humidity);
    if (res != 0)
    {
        (void)sht30_shot_deinit();

        return 1;
    }
    sht30_interface_debug_print("sht30: temperature is %0.2fC.\n", temperature);
    sht30_interface_debug_print("sht30: humidity is %0.2f%%.\n", humidity);
    
    ...
    
}

...

(void)sht30_shot_deinit();

return 0;
```

### ドキュメント

オンラインドキュメント: [https://www.libdriver.com/docs/sht30/index.html](https://www.libdriver.com/docs/sht30/index.html)。

オフラインドキュメント: /doc/html/index.html。

### 貢献

CONTRIBUTING.mdを参照してください。

### 著作権

著作権（c）2015-今 LibDriver 全著作権所有

MITライセンス（MIT）

このソフトウェアおよび関連するドキュメントファイル（「ソフトウェア」）のコピーを取得した人は、無制限の使用、複製、変更、組み込み、公開、配布、サブライセンスを含む、ソフトウェアを処分する権利を制限なく付与されます。ソフトウェアのライセンスおよび/またはコピーの販売、および上記のようにソフトウェアが配布された人の権利のサブライセンスは、次の条件に従うものとします。

上記の著作権表示およびこの許可通知は、このソフトウェアのすべてのコピーまたは実体に含まれるものとします。

このソフトウェアは「現状有姿」で提供され、商品性、特定目的への適合性、および非侵害の保証を含むがこれらに限定されない、明示または黙示を問わず、いかなる種類の保証もありません。 いかなる場合も、作者または著作権所有者は、契約、不法行為、またはその他の方法で、本ソフトウェアおよび本ソフトウェアの使用またはその他の廃棄に起因または関連して、請求、損害、またはその他の責任を負わないものとします。

### 連絡して

お問い合わせくださいlishifenging@outlook.com。